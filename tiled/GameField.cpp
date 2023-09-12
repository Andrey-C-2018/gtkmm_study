#include <cassert>
#include <glibmm/main.h>
#include "GameField.h"

GameField::GameField() : game_screen(this) {

	add_events(Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK | \
						Gdk::KEY_PRESS_MASK | Gdk::KEY_RELEASE_MASK);
	set_can_focus(true);
}

bool GameField::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {

	return game_screen.draw(cr);
}

void GameField::init(EvtHandlerPtr evt_handler_) {

	assert(evt_handler_);
	assert(!evt_handler);
	evt_handler = evt_handler_;
	evt_handler->onInit(game_screen);
}

void GameField::enableTimer() {

    Glib::signal_timeout().connect(sigc::bind(sigc::mem_fun(*this,
                                         &GameField::on_timeout), 0), 50);
}

bool GameField::on_button_press_event(GdkEventButton *event) {

	if (event->type == GDK_BUTTON_PRESS) {
		game_screen.screenSizeChanged(get_allocation());
		size_t col = game_screen.getColByXCoord(event->x);
		size_t row = game_screen.getRowByYCoord(event->y);

		switch (event->button) {
			case 1:
				evt_handler->onMouseLButtonDown(col, row);
				break;
			case 2:
				evt_handler->onMouseWheelDown(col, row);
				break;
			case 3:
				evt_handler->onMouseRButtonDown(col, row);
		}
		return true;
	}
	return false;
}

bool GameField::on_button_release_event(GdkEventButton *event) {

	assert (event->type == GDK_BUTTON_RELEASE);
	game_screen.screenSizeChanged(get_allocation());
	size_t col = game_screen.getColByXCoord(event->x);
	size_t row = game_screen.getRowByYCoord(event->y);

	switch (event->button) {
		case 1:
			evt_handler->onMouseLButtonUp(col, row);
			break;
		case 2:
			evt_handler->onMouseWheelUp(col, row);
			break;
		case 3:
			evt_handler->onMouseRButtonUp(col, row);
	}
	return true;
}

bool GameField::on_key_press_event(GdkEventKey *event) {

	assert (event->type == GDK_KEY_PRESS);
	evt_handler->onKeyPress((char)event->keyval);
	return true;
}

bool GameField::on_key_release_event(GdkEventKey *event) {

	assert (event->type == GDK_KEY_RELEASE);
	evt_handler->onKeyReleased((char)event->keyval);
	return true;
}

bool GameField::on_timeout(int timer_number) {

    evt_handler->onTimer();
    return true;
}

GameField::~GameField() = default;

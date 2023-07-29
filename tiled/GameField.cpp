#include <cassert>
#include "GameField.h"

GameField::GameField() : game_screen(this) {

	add_events(Gdk::BUTTON_PRESS_MASK | \
						Gdk::KEY_PRESS_MASK | Gdk::KEY_RELEASE_MASK);
	set_can_focus(true);
}

bool GameField::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {

	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	return game_screen.draw(cr, width, height);
}

void GameField::init(EvtHandlerPtr evt_handler_) {

	assert(evt_handler_);
	assert(!evt_handler);
	evt_handler = std::move(evt_handler_);
	evt_handler->onInit(game_screen);
}

bool GameField::on_button_press_event(GdkEventButton *event) {

	if (event->type == GDK_BUTTON_PRESS) {
		if (event->button == 1)
			evt_handler->onMouseLButtonClick(game_screen, 1, 0);

		if (event->button == 2)
			evt_handler->onMouseWheelClick(game_screen, 0, 1);

		if (event->button == 3)
			evt_handler->onMouseRButtonClick(game_screen, 1, 1);
	}

	return true;
}

bool GameField::on_key_press_event(GdkEventKey *event) {

	assert (event->type == GDK_KEY_PRESS);
	evt_handler->onKeyPress(game_screen, (char)event->keyval);
	return true;
}

bool GameField::on_key_release_event(GdkEventKey *event) {

	assert (event->type == GDK_KEY_RELEASE);
	evt_handler->onKeyReleased(game_screen, (char)event->keyval);
	return true;
}

GameField::~GameField() { }
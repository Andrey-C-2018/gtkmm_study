#include <cassert>
#include "GameField.h"

GameField::GameField() { }

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

GameField::~GameField() { }
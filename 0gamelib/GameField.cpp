#include <cassert>
#include <gtkmm.h>
#include "GameField.h"

GameField::GameField() :is_initialized(false), cols(0), rows(0) { }

void GameField::initScreen(size_t cols_, size_t rows_, Gdk::Color def_color, \
						   std::unique_ptr<IGameEventsHandler> evt_handler_) {

	assert(cols_);
	assert(rows_);
	assert (evt_handler_);
	if (is_initialized)
		throw std::logic_error("the screen has been already initialized");

	is_initialized = true;
	cols = cols_;
	rows = rows_;
	evt_handler = std::move(evt_handler_);

	CellProperties cell_props{def_color, ""};
	std::vector<CellProperties> row(cols, cell_props);
	cells.insert(cells.begin(), rows, row);
}

void GameField::setCellColor(size_t col, size_t row, Gdk::Color color) {

	assert (col < cols);
	assert (row < rows);
	cells[row][col].color = color;
}

void GameField::setCellText(size_t col, size_t row, const char *text) {

	assert (col < cols);
	assert (row < rows);
	cells[row][col].text = text;
}

void GameField::setTimer(unsigned int duration) {

	sigc::slot<bool> slot = sigc::bind(sigc::mem_fun(*this,
											&GameField::on_timeout), 0);
	timer_conn = Glib::signal_timeout().connect(slot, duration);
}

void GameField::stopTimer() {

	timer_conn.disconnect();
}

void GameField::redraw() {

	Glib::RefPtr<Gdk::Window> win = get_window();
	if (win) {
		Gdk::Rectangle r(0, 0, get_allocation().get_width(),
						 get_allocation().get_height());
		win->invalidate_rect(r, false);
	}
}

void GameField::reset(Gdk::Color color) {

	for (auto& cells_row : cells) {
		for (auto &cell_props: cells_row) {
			cell_props.color = color;
			cell_props.text.clear();
		}
	}
	redraw();
}

bool GameField::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {

	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();
	const double cell_width = width / (double) cells[0].size();
	const double cell_height = height / (double) cells.size();

	for (size_t i = 0; i < cells.size(); i++) {
		for (size_t j = 0; j < cells[i].size(); j++) {
			CellProperties &cell_props = cells[i][j];
			Gdk::Color &c = cell_props.color;

			cr->set_source_rgb(c.get_red_p(), c.get_green_p(), c.get_blue_p());
			cr->rectangle(cell_width * (double)j, cell_height * (double)i,
						  cell_width, cell_height);
		}
	}
	return true;
}

bool GameField::on_timeout(int ignored) {

	evt_handler->onTimer();
	return true;
}

GameField::~GameField() {

	timer_conn.disconnect();
}

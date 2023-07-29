#include <cassert>
#include "GameScreen.h"

GameScreen::GameScreen(Gtk::DrawingArea *parent_) : \
						parent(parent_), cell_width(0), cell_height(0), \
						cols(0), rows(0) {

	assert(parent);
	screenSizeChanged(parent->get_allocation());
}

void GameScreen::screenSizeChanged(const Gtk::Allocation &allocation) {

	int width = allocation.get_width();
	int height = allocation.get_height();
	cell_width = cols != 0 ? width / (int)cols : 0;
	cell_height = rows != 0 ? height / (int)rows : 0;
}

size_t GameScreen::getColByXCoord(gdouble x) const {

	auto col = (size_t) (x / (gdouble)cell_width);
	assert (col < cols);
	return col;
}

size_t GameScreen::getRowByYCoord(gdouble y) const {

	auto row = (size_t) (y / (gdouble)cell_height);
	assert (row < rows);
	return row;
}

void GameScreen::setSize(size_t cols_, size_t rows_, Color def_color) {

	assert(cols_);
	assert(rows_);
	cols = cols_;
	rows = rows_;

	CellProperties cell_props{def_color, ""};
	std::vector<CellProperties> row(cols, cell_props);
	cells.insert(cells.begin(), rows, row);
	screenSizeChanged(parent->get_allocation());
}

void GameScreen::setCellColor(size_t col, size_t row, Color color) {

	assert (col < cols);
	assert (row < rows);
	cells[row][col].color = color;
}

void GameScreen::setCellText(size_t col, size_t row, const char *text) {

	assert (col < cols);
	assert (row < rows);
	cells[row][col].text = text;
}

void GameScreen::reset(Color color) {

	for (auto& cells_row : cells) {
		for (auto &cell_props: cells_row) {
			cell_props.color = color;
			cell_props.text.clear();
		}
	}
}

bool GameScreen::draw(const DrawingContext &cr) {

	screenSizeChanged(parent->get_allocation());
	for (size_t i = 0; i < cells.size(); i++) {
		for (size_t j = 0; j < cells[i].size(); j++) {
			CellProperties &cell_props = cells[i][j];
			Color &c = cell_props.color;

			cr->save();
			cr->set_source_rgb(c.getRed() / 255.0,
							   c.getGreen() / 255.0,
							   c.getBlue() / 255.0);
			cr->rectangle(cell_width * (double)j, cell_height * (double)i, \
						  cell_width, cell_height);
			cr->fill_preserve();
			cr->restore();
			drawText(cr, cell_width * (double)j + cell_width / 2.0, \
						cell_height * (double)i + cell_height / 2.0, \
						cell_props.text.c_str());
			cr->stroke();
		}
	}
	return true;
}

void GameScreen::drawText(const DrawingContext &cr, \
							double x, double y, const char *text) {

	Pango::FontDescription font;
	font.set_family("Monospace");
	font.set_weight(Pango::WEIGHT_BOLD);

	auto layout = parent->create_pango_layout(text);
	layout->set_font_description(font);

	int text_width;
	int text_height;
	layout->get_pixel_size(text_width, text_height);

	cr->move_to(x - text_width / 2.0, y - text_height / 2.0);
	layout->show_in_cairo_context(cr);
}

void GameScreen::redraw() {

	parent->queue_draw();
}

GameScreen::~GameScreen() { }

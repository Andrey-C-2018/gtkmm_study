#include <cassert>
#include "GameScreen.h"

GameScreen::GameScreen() : cols(0), rows(0) { }

void GameScreen::setSize(size_t cols_, size_t rows_, Color def_color) {

	assert(cols_);
	assert(rows_);
	cols = cols_;
	rows = rows_;

	CellProperties cell_props{def_color, ""};
	std::vector<CellProperties> row(cols, cell_props);
	cells.insert(cells.begin(), rows, row);
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

bool GameScreen::draw(const DrawingContext &cr, \
						int screen_width, int screen_height) {

	size_t cols_count = cells.empty() ? 1 : cells[0].size();
	size_t rows_count = cells.empty() ? 1 : cells.size();
	const double cell_width = screen_width / (double) cols_count;
	const double cell_height = screen_height / (double) rows_count;

	for (size_t i = 0; i < cells.size(); i++) {
		for (size_t j = 0; j < cells[i].size(); j++) {
			CellProperties &cell_props = cells[i][j];
			Color &c = cell_props.color;

			cr->set_source_rgb(c.getRed() / 255.0,
							   c.getGreen() / 255.0,
							   c.getBlue() / 255.0);
			cr->rectangle(cell_width * (double)j, cell_height * (double)i,
						  cell_width, cell_height);
			cr->stroke();
		}
	}
	return true;
}

GameScreen::~GameScreen() { }

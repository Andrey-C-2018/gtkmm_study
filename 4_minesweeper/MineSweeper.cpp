#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <tiled/IGameScreen.h>
#include "MineSweeper.h"

MineSweeper::MineSweeper() : \
		INITIAL(100, 100, 100), \
		OPENED(0, 0xff, 0), \
		MINED(0xff, 0, 0), \
		MARKED(0, 0xff, 0xff) {

	Cell ordinary{false, false, false};
	std::fill(&cells[0][0], &cells[0][0] + COLS * ROWS, ordinary);
	Cell mined_cell{false, true, false};
	std::fill_n(&cells[0][0], MINES_MAX_COUNT, mined_cell);

	std::default_random_engine urng(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(&cells[0][0], &cells[0][0] + COLS * ROWS, urng);

	std::vector<Cell *> neighbours;
	neighbours.reserve(8);
	for (size_t i = 0; i < COLS; i++)
		for (size_t j = 0; j < ROWS; j++)
			if (cells[i][j].is_mined) {
				getNeighbours(i, j, neighbours);
				for (auto neighbour : neighbours)
					neighbour->mined_neighbours++;
			}
}

std::vector<MineSweeper::Cell *>& \
        MineSweeper::getNeighbours(size_t col, size_t row, \
									std::vector<Cell *> &neighbours) {

	neighbours.clear();
	size_t initial_i = col > 0 ? col - 1 : 0;
	size_t initial_j = row > 0 ? row - 1 : 0;
	for(size_t i = initial_i; i <= col + 1; i++)
		for(size_t j = initial_j; j <= row + 1; j++) {
			if (i >= COLS || j >= ROWS || \
				(i == col && j == row)) continue;

			neighbours.push_back(&cells[i][j]);
		}
	assert (neighbours.size() <= 8);
	return neighbours;
}

void MineSweeper::onInit(IGameScreen &screen) {

	screen.setSize(COLS, ROWS, INITIAL);
}

void MineSweeper::onMouseLButtonClick(IGameScreen &screen, size_t col, size_t row) {

	Cell &cell = cells[col][row];
	if (cell.is_open || cell.is_marked) return;
	cell.is_open = true;

	if (cell.is_mined) {
		boom(screen, col, row);
		return;
	}

	screen.setCellColor(col, row, OPENED);
	cell.label = std::to_string(cell.mined_neighbours);
	if (cell.mined_neighbours > 0)
		screen.setCellText(col, row, cell.label.c_str());
	else {

	}

	screen.redraw();
}

void MineSweeper::boom(IGameScreen &screen, size_t col, size_t row) {

	screen.setCellColor(col, row, MINED);
	screen.setCellText(col, row, "M");
	screen.redraw();
}

void MineSweeper::onMouseWheelClick(IGameScreen &screen, size_t col, size_t row) { }

void MineSweeper::onMouseRButtonClick(IGameScreen &screen, size_t col, size_t row) {

	Cell &cell = cells[col][row];
	if (cell.is_open) return;

	if (cell.is_marked) {
		screen.setCellColor(col, row, INITIAL);
		screen.setCellText(col, row, "");
	}
	else {
		screen.setCellColor(col, row, MARKED);
		screen.setCellText(col, row, "F");
	}
	cell.is_marked = !cell.is_marked;
	screen.redraw();
}

void MineSweeper::onKeyPress(IGameScreen &screen, char ch) { }

void MineSweeper::onKeyReleased(IGameScreen &screen, char ch) { }

MineSweeper::~MineSweeper() { }

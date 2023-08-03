#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <tiled/IGameScreen.h>
#include <tiled/MessageBox.h>
#include "MineSweeper.h"

MineSweeper::MineSweeper() : \
		INITIAL(100, 100, 100), \
		OPENED(0, 0xff, 0), \
		MINED(0xff, 0, 0), \
		MARKED(0xff, 0xff, 0), \
		closed_cells_count(COLS * ROWS), \
		flags_count(0), \
		game_over(false) {

	Cell ordinary{false, false, false};
	std::fill(&cells[0][0], &cells[0][0] + COLS * ROWS, ordinary);
	Cell mined_cell{false, true, false};
	std::fill_n(&cells[0][0], MINES_MAX_COUNT, mined_cell);

	std::default_random_engine urng(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(&cells[0][0], &cells[0][0] + COLS * ROWS, urng);

	fillMinedNeighboursCounts();
}

void MineSweeper::fillMinedNeighboursCounts() {

	Cell *neighbours[8];
	for (size_t i = 0; i < COLS; i++) {
		for (size_t j = 0; j < ROWS; j++) {
			if (cells[i][j].is_mined) {
				size_t count = getNeighbours(i, j, neighbours);
				for (size_t k = 0; k < count; k++)
					neighbours[k]->mined_neighbours++;
			}
		}
	}
}

size_t MineSweeper::getNeighbours(size_t col, size_t row, \
									Cell *neighbours[8]) {

	size_t count = 0;
	size_t initial_i = col > 0 ? col - 1 : 0;
	size_t initial_j = row > 0 ? row - 1 : 0;
	for(size_t i = initial_i; i <= col + 1; i++) {
		for (size_t j = initial_j; j <= row + 1; j++) {
			if (i >= COLS || j >= ROWS || \
                (i == col && j == row))
				continue;

			assert (count < 8);
			neighbours[count++] = &cells[i][j];
		}
	}
	return count;
}

void MineSweeper::onInit(IGameScreen &screen) {

	screen.setSize(COLS, ROWS, INITIAL);
}

void MineSweeper::openCell(IGameScreen &screen, size_t col, size_t row) {

	Cell &cell = cells[col][row];
	if (game_over || cell.is_open || cell.is_marked) return;
	cell.is_open = true;
	closed_cells_count--;

	if (cell.is_mined) {
		boom(screen, col, row);
		return;
	}

	screen.setCellColor(col, row, OPENED);
	if (closed_cells_count == MINES_MAX_COUNT) {
		game_over = true;
		MessageBox::showMessage("", "you win!");
	}
	if (cell.mined_neighbours > 0) {
		cell.label = std::to_string(cell.mined_neighbours);
		screen.setCellText(col, row, cell.label.c_str());
	}
	else {
		Cell *neighbours[8];
		size_t count = getNeighbours(col, row, neighbours);
		for (size_t i = 0; i < count; i++) {
			Cell *c = neighbours[i];
			if (!(c->is_mined || c->is_marked || c->is_open)) {
				auto location = getCellLocation(c);
				openCell(screen, location.first, location.second);
			}
		}
	}
}

std::pair<size_t, size_t> MineSweeper::getCellLocation(const Cell *cell) const {

	const Cell *first = &cells[0][0];
	size_t dist = std::distance(first, cell);
	return {dist / COLS, dist % COLS};
}

void MineSweeper::boom(IGameScreen &screen, size_t col, size_t row) {

	game_over = true;
	screen.setCellColor(col, row, MINED);
	screen.setCellText(col, row, "M");
	MessageBox::showMessage("", "you lose");
}

void MineSweeper::onMouseLButtonDown(IGameScreen &screen, size_t col, size_t row) {

	openCell(screen, col, row);
	screen.redraw();
}

void MineSweeper::onMouseWheelDown(IGameScreen &screen, size_t col, size_t row) {

	Cell &cell = cells[col][row];
	if(game_over || \
		!(!cell.is_mined && cell.is_open && cell.mined_neighbours > 0)) return;

	Cell *neighbours[8];
	size_t count = getNeighbours(col, row, neighbours);
	for(int i = 0; i < count; ++i) {
		auto location = getCellLocation(neighbours[i]);
		openCell(screen, location.first, location.second);
	}
	screen.redraw();
}

void MineSweeper::onMouseRButtonDown(IGameScreen &screen, size_t col, size_t row) {

	Cell &cell = cells[col][row];
	if (game_over || cell.is_open || \
		(flags_count == MINES_MAX_COUNT && !cell.is_marked)) return;

	if (cell.is_marked) {
		flags_count--;
		screen.setCellColor(col, row, INITIAL);
		screen.setCellText(col, row, "");
	}
	else {
		flags_count++;
		screen.setCellColor(col, row, MARKED);
		screen.setCellText(col, row, "F");
	}
	cell.is_marked = !cell.is_marked;
	screen.redraw();
}

MineSweeper::~MineSweeper() { }

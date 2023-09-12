#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <tiled/IEventsHandler.h>
#include <tiled/Color.h>
#include "INotifier.h"

class MineSweeper : public IEventsHandler {
	struct Cell {
		bool is_open, is_mined, is_marked;
		std::string label;
		size_t mined_neighbours;
	};

	static const char MINE_EMOJI[];
	static const char FLAG_EMOJI[];
	const Color INITIAL, OPENED, MINED, MARKED;

	size_t cols_count, rows_count, mines_count;
	std::vector<Cell> cells;
	size_t closed_cells_count, flags_count;
	bool game_over, opening_allowed;
	IGameScreen *screen;
	INotifier *notifier;

	void resetCells();
	void fillMinedNeighboursCounts();

	void openCell(size_t col, size_t row);
	inline Cell &getCell(size_t col, size_t row);
	size_t getNeighbours(size_t col, size_t row, Cell *neighbours[8]);
	inline std::pair<size_t, size_t> getCellLocation(const Cell *cell) const;

	void boom(size_t col, size_t row);
	inline void visualizeMarkOnCell(size_t col, size_t row);
	void finalizeIfWin();

public:
	explicit MineSweeper(INotifier *notifier);

	void onInit(IGameScreen &screen) override;
	void onMouseLButtonDown(size_t col, size_t row) override;
	void onMouseLButtonUp(size_t col, size_t row) override { }
	void onMouseWheelDown(size_t col, size_t row) override;
	void onMouseWheelUp(size_t col, size_t row) override;
	void onMouseRButtonDown(size_t col, size_t row) override;
	void onMouseRButtonUp(size_t col, size_t row) override { }
	void onKeyPress(char ch) override { }
	void onKeyReleased(char ch) override { }
    void onTimer() override { }

    void reset();
	void reset(size_t cols_count, size_t rows_count, size_t mines_count);

	~MineSweeper() override;
};

//*************************************************

MineSweeper::Cell &MineSweeper::getCell(size_t col, size_t row) {

	assert (col < cols_count);
	assert (row < rows_count);
	return cells[cols_count * row + col];
}

std::pair<size_t, size_t> MineSweeper::getCellLocation(const Cell *cell) const {

	const Cell *first = &cells[0];
	size_t dist = std::distance(first, cell);
	return {dist % cols_count, dist / cols_count};
}

void MineSweeper::visualizeMarkOnCell(size_t col, size_t row) {

	screen->setCellColor(col, row, MARKED);
	screen->setCellText(col, row, FLAG_EMOJI);
}
#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <tiled/IEventsHandler.h>
#include <tiled/Color.h>
#include "INotifier.h"

class MineSweeper : public IEventsHandler {
	enum Constants {
		COLS = 8, ROWS = 8, MINES_MAX_COUNT = 10
	};
	static const char MINE_EMOJI[];
	static const char FLAG_EMOJI[];

	const Color INITIAL, OPENED, MINED, MARKED;

	struct Cell {
		bool is_open, is_mined, is_marked;
		std::string label;
		size_t mined_neighbours;
	};
	std::vector<Cell> cells;
	size_t closed_cells_count, flags_count;
	bool game_over, opening_allowed;
	IGameScreen *screen;
	INotifier *notifier;

	void resetCells();
	void fillMinedNeighboursCounts();
	inline Cell &getCell(size_t col, size_t row);
	void openCell(size_t col, size_t row);
	inline void visualizeMarkOnCell(size_t col, size_t row);
	size_t getNeighbours(size_t col, size_t row, Cell *neighbours[8]);
	std::pair<size_t, size_t> getCellLocation(const Cell *cell) const;
	void boom(size_t col, size_t row);
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

	void reset();

	virtual ~MineSweeper();
};

//*************************************************

MineSweeper::Cell &MineSweeper::getCell(size_t col, size_t row) {

	assert (col < COLS);
	assert (row < ROWS);
	return cells[COLS * row + col];
}

void MineSweeper::visualizeMarkOnCell(size_t col, size_t row) {

	screen->setCellColor(col, row, MARKED);
	screen->setCellText(col, row, FLAG_EMOJI);
}
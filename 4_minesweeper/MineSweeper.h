#pragma once
#include <memory>
#include <string>
#include <tiled/IEventsHandler.h>
#include <tiled/Color.h>
#include "IMessenger.h"

class MineSweeper : public IEventsHandler {
	enum Constants {
		COLS = 8, ROWS = 8, MINES_MAX_COUNT = 10
	};
	const Color INITIAL, OPENED, MINED, MARKED;

	struct Cell {
		bool is_open, is_mined, is_marked;
		std::string label;
		size_t mined_neighbours;
	};
	Cell cells[COLS][ROWS]{};
	size_t closed_cells_count, flags_count;
	bool game_over;
	IGameScreen *screen;
	std::unique_ptr<IMessenger> messenger;

	void resetCells();
	void fillMinedNeighboursCounts();
	void openCell(size_t col, size_t row);
	size_t getNeighbours(size_t col, size_t row, Cell *neighbours[8]);
	std::pair<size_t, size_t> getCellLocation(const Cell *cell) const;
	void boom(size_t col, size_t row);

public:
	MineSweeper(std::unique_ptr<IMessenger> messenger);

	void onInit(IGameScreen &screen) override;
	void onMouseLButtonDown(size_t col, size_t row) override;
	void onMouseLButtonUp(size_t col, size_t row) override { }
	void onMouseWheelDown(size_t col, size_t row) override;
	void onMouseWheelUp(size_t col, size_t row) override { }
	void onMouseRButtonDown(size_t col, size_t row) override;
	void onMouseRButtonUp(size_t col, size_t row) override { }
	void onKeyPress(char ch) override { }
	void onKeyReleased(char ch) override { }

	void reset();

	virtual ~MineSweeper();
};

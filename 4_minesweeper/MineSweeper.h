#pragma once
#include <string>
#include <tiled/IEventsHandler.h>
#include <tiled/Color.h>

class MineSweeper : public IEventsHandler {
	enum Constants {
		COLS = 16, ROWS = 16, MINES_MAX_COUNT = 40
	};
	const Color INITIAL, OPENED, MINED, MARKED;

	struct Cell {
		bool is_open, is_mined, is_marked;
		std::string label;
		size_t mined_neighbours;
	};
	Cell cells[COLS][ROWS]{};
	bool game_over;

	void openCell(IGameScreen &screen, size_t col, size_t row);
	size_t getNeighbours(size_t col, size_t row, Cell *neighbours[8]);
	std::pair<size_t, size_t> getCellLocation(const Cell *cell) const;
	void boom(IGameScreen &screen, size_t col, size_t row);

public:
	MineSweeper();

	void onInit(IGameScreen &screen) override;
	void onMouseLButtonDown(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseLButtonUp(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseWheelDown(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseWheelUp(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseRButtonDown(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseRButtonUp(IGameScreen &screen, size_t col, size_t row) override;
	void onKeyPress(IGameScreen &screen, char ch) override;
	void onKeyReleased(IGameScreen &screen, char ch) override;

	virtual ~MineSweeper();
};

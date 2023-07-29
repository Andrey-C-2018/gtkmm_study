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
	std::vector<Cell*> &getNeighbours(size_t col, size_t row, \
										std::vector<Cell*> &neighbours);
	void boom(IGameScreen &screen, size_t col, size_t row);

public:
	MineSweeper();

	void onInit(IGameScreen &screen) override;
	void onMouseLButtonClick(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseWheelClick(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseRButtonClick(IGameScreen &screen, size_t col, size_t row) override;
	void onKeyPress(IGameScreen &screen, char ch) override;
	void onKeyReleased(IGameScreen &screen, char ch) override;

	virtual ~MineSweeper();
};

#pragma once
#include "Color.h"

struct IGameScreen {

	virtual void setSize(size_t cols, size_t rows, Color def_color) = 0;
	virtual void setCellColor(size_t col, size_t row, Color color) = 0;
	virtual void setCellText(size_t col, size_t row, const char *text) = 0;
	virtual void redraw() = 0;
	virtual void reset(Color color) = 0;

	virtual ~IGameScreen() = default;
};

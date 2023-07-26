#pragma once
#include <memory>
#include "Color.h"

struct IGameEventsHandler;

struct IGameField {

	virtual void init(size_t cols, size_t rows, Color def_color, \
							std::unique_ptr<IGameEventsHandler> evt_handler) = 0;
	virtual void setCellColor(size_t col, size_t row, Color color) = 0;
	virtual void setCellText(size_t col, size_t row, const char *text) = 0;

	virtual void setTimer(unsigned duration) = 0;
	virtual void stopTimer() = 0;

	virtual void redraw() = 0;
	virtual void reset(Color color) = 0;

	virtual ~IGameField() { }
};

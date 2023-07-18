#pragma once
#include <cstddef>

struct IGameEventsHandler {

	virtual void onMouseLButtonClick(size_t col, size_t row) = 0;
	virtual void onMouseWheelClick(size_t col, size_t row) = 0;
	virtual void onMouseRButtonClick(size_t col, size_t row) = 0;
	virtual void onKeyPress(char ch) = 0;
	virtual void onKeyReleased(char ch) = 0;
	virtual void onTimer() = 0;

	virtual ~IGameEventsHandler() { }
};
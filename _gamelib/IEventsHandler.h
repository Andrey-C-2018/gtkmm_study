#pragma once
#include <cstddef>

struct IGameScreen;

struct IEventsHandler {

	virtual void onInit(IGameScreen &screen) = 0;
	virtual void onMouseLButtonClick(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseWheelClick(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseRButtonClick(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onKeyPress(IGameScreen &screen, char ch) = 0;
	virtual void onKeyReleased(IGameScreen &screen, char ch) = 0;

	virtual ~IEventsHandler() { }
};
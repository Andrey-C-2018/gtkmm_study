#pragma once
#include <cstddef>

struct IGameScreen;

struct IEventsHandler {

	virtual void onInit(IGameScreen &screen) = 0;
	virtual void onMouseLButtonDown(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseLButtonUp(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseWheelDown(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseWheelUp(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseRButtonDown(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onMouseRButtonUp(IGameScreen &screen, size_t col, size_t row) = 0;
	virtual void onKeyPress(IGameScreen &screen, char ch) = 0;
	virtual void onKeyReleased(IGameScreen &screen, char ch) = 0;

	virtual ~IEventsHandler() { }
};
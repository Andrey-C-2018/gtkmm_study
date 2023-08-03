#pragma once
#include <cstddef>

struct IGameScreen;

struct IEventsHandler {

	virtual void onInit(IGameScreen &screen) = 0;
	virtual void onMouseLButtonDown(size_t col, size_t row) = 0;
	virtual void onMouseLButtonUp(size_t col, size_t row) = 0;
	virtual void onMouseWheelDown(size_t col, size_t row) = 0;
	virtual void onMouseWheelUp(size_t col, size_t row) = 0;
	virtual void onMouseRButtonDown(size_t col, size_t row) = 0;
	virtual void onMouseRButtonUp(size_t col, size_t row) = 0;
	virtual void onKeyPress(char ch) = 0;
	virtual void onKeyReleased(char ch) = 0;

	virtual ~IEventsHandler() { }
};
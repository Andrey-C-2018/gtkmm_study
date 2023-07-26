#pragma once
#include <_gamelib/IGameEventsHandler.h>

class EvtHandler : public IGameEventsHandler {
public:
	void onMouseLButtonClick(size_t col, size_t row) override { }
	void onMouseWheelClick(size_t col, size_t row) override { }
	void onMouseRButtonClick(size_t col, size_t row) override { }
	void onKeyPress(char ch) override { }
	void onKeyReleased(char ch) override { }
	void onTimer() override { }

	virtual ~EvtHandler() { }
};

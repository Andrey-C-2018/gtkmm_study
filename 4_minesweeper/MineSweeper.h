#pragma once
#include <tiled/IEventsHandler.h>

class MineSweeper : public IEventsHandler {
public:
	void onInit(IGameScreen &screen) override;
	void onMouseLButtonClick(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseWheelClick(IGameScreen &screen, size_t col, size_t row) override;
	void onMouseRButtonClick(IGameScreen &screen, size_t col, size_t row) override;
	void onKeyPress(IGameScreen &screen, char ch) override;
	void onKeyReleased(IGameScreen &screen, char ch) override;
};

#pragma once
#include <gdkmm/color.h>

struct IGameField {

	void initScreen(int cols, int rows, Gdk::Color def_color);
	void setCellColor(int col, int row, Gdk::Color color);
	void setCellText(int col, int row, const char *text);
	
	void onMouseLButtonClick(int col, int row);
	void onMouseWheelClick(int col, int row);
	void onMouseRButtonClick(int col, int row);
	
	void onKeyPress(char ch);
	void onKeyReleased(char ch);
	
	void setTimer(unsigned duration);
	void onTimer();
	void stopTimer();

	void redraw();
	void reset(Gdk::Color color);
};

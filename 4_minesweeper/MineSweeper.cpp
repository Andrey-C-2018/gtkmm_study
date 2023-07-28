#include "MineSweeper.h"
#include <tiled/IGameScreen.h>

void MineSweeper::onInit(IGameScreen &screen) {

	screen.setSize(3, 3, Color(0, 0xff, 0));
	screen.setCellText(0, 0, "OK");
}

void MineSweeper::onMouseLButtonClick(IGameScreen &screen, size_t col, size_t row) {

	screen.setCellColor(col, row, Color(0xff, 0, 0));
	screen.redraw();
}

void MineSweeper::onMouseWheelClick(IGameScreen &screen, size_t col, size_t row) {

	screen.setCellColor(col, row, Color(0xff, 0xff, 0xff));
	screen.redraw();
}

void MineSweeper::onMouseRButtonClick(IGameScreen &screen, size_t col, size_t row) {

	screen.setCellColor(col, row, Color(0xff, 0, 0xff));
	screen.redraw();
}

void MineSweeper::onKeyPress(IGameScreen &screen, char ch) {

}

void MineSweeper::onKeyReleased(IGameScreen &screen, char ch) {

}

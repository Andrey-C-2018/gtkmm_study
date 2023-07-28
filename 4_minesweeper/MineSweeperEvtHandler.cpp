#include "MineSweeperEvtHandler.h"
#include <_gamelib/IGameScreen.h>

void MineSweeperEvtHandler::onInit(IGameScreen &screen) {

	screen.setSize(3, 3, Color(0, 0xff, 0));
	screen.setCellText(0, 0, "OK");
}

void MineSweeperEvtHandler::onMouseLButtonClick(IGameScreen &screen, size_t col, size_t row) {

}

void MineSweeperEvtHandler::onMouseWheelClick(IGameScreen &screen, size_t col, size_t row) {

}

void MineSweeperEvtHandler::onMouseRButtonClick(IGameScreen &screen, size_t col, size_t row) {

}

void MineSweeperEvtHandler::onKeyPress(IGameScreen &screen, char ch) {

}

void MineSweeperEvtHandler::onKeyReleased(IGameScreen &screen, char ch) {

}

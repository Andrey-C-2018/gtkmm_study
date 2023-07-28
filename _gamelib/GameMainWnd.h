#pragma once
#include <gtkmm/window.h>
#include "GameField.h"

class GameMainWnd : public Gtk::Window {
	GameField field;

public:
	GameMainWnd();

	GameMainWnd(const GameMainWnd &obj) = delete;
	GameMainWnd(GameMainWnd &&obj) = default;
	GameMainWnd& operator=(const GameMainWnd &obj) = delete;
	GameMainWnd& operator=(GameMainWnd &&obj) = default;

	inline GameField &getGameField();

    virtual ~GameMainWnd();
};

//**********************************

GameField &GameMainWnd::getGameField() {

	return field;
}
#pragma once
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <tiled/GameField.h>
#include "MineSweeper.h"

class MainWnd : public Gtk::Window {
	std::shared_ptr<MineSweeper> mine_sweeper;
	Gtk::Box vert_box;
	Gtk::Button restart_btn;
	GameField field;

protected:
	void onRestartBtnClicked();

public:
	MainWnd(const char *title, int width, int height);

	MainWnd(const MainWnd &obj) = delete;
	MainWnd(MainWnd &&obj) = default;
	MainWnd& operator=(const MainWnd &obj) = delete;
	MainWnd& operator=(MainWnd &&obj) = default;

    virtual ~MainWnd();
};

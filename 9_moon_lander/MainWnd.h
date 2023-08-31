#pragma once
#include <gtkmm/window.h>
#include <tiled/GameField.h>
#include "MoonLander.h"

class MainWnd : public Gtk::Window {
    std::shared_ptr<MoonLander> moon_lander;
    GameField field;

public:
	MainWnd();

	MainWnd(const MainWnd &obj) = delete;
	MainWnd(MainWnd &&obj) = default;
	MainWnd& operator=(const MainWnd &obj) = delete;
	MainWnd& operator=(MainWnd &&obj) = default;

	~MainWnd() override;
};

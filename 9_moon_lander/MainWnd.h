#pragma once
#include <gtkmm/window.h>
#include <tiled/GameField.h>
#include "MoonLander.h"

class MainWnd : public Gtk::Window {
    GameField field;
    std::shared_ptr<MoonLander> moon_lander;

    void setResizeConstraints();

public:
	MainWnd();

	MainWnd(const MainWnd &obj) = delete;
	MainWnd(MainWnd &&obj) = default;
	MainWnd& operator=(const MainWnd &obj) = delete;
	MainWnd& operator=(MainWnd &&obj) = default;

	~MainWnd() override;
};

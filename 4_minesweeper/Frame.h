#pragma once
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <_gamelib/GameField.h>

class Frame : public Gtk::Window {
	GameField field;

public:
    Frame();

    Frame(const Frame &obj) = delete;
    Frame(Frame &&obj) = default;
    Frame& operator=(const Frame &obj) = delete;
    Frame& operator=(Frame &&obj) = default;

    virtual ~Frame(); 
};

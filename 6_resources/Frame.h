#pragma once
#include <gtkmm/window.h>
#include "DrawingArea.h"

class Frame : public Gtk::Window {
	DrawingArea area; 

public:
	Frame();

	Frame(const Frame &obj) = delete;
	Frame(Frame &&obj) = default;
	Frame& operator=(const Frame &obj) = delete;
	Frame& operator=(Frame &&obj) = default;

	virtual ~Frame(); 
};

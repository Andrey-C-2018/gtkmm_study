#pragma once
#include <gtkmm/window.h>
#include <gtkmm/toolbutton.h>
#include <gtkmm/hvbox.h>

class Frame : public Gtk::Window {
	static constexpr size_t COUNT = 8;
	static constexpr size_t TRIANGLES_COUNT = 3;
	static constexpr size_t BLANKS_COUNT = 2;

	Gtk::HBox box;
	Gtk::Image tr_img[2 * TRIANGLES_COUNT], blank_img[BLANKS_COUNT];
	Gtk::ToolButton buttons[COUNT];

public:
	Frame();

	Frame(const Frame &obj) = delete;
	Frame(Frame &&obj) = default;
	Frame& operator=(const Frame &obj) = delete;
	Frame& operator=(Frame &&obj) = default;

	virtual ~Frame(); 
};

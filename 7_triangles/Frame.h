#pragma once
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/toolbutton.h>
#include <gtkmm/hvbox.h>
#include "ICellsView.h"
#include "Triangles.h"

class Frame : public Gtk::Window, public ICellsView {
	Gtk::HBox box;
	Glib::RefPtr<Gdk::Pixbuf> left, right, blank;
	std::vector<Gtk::Image> images;
	std::vector<Gtk::ToolButton> buttons;
	Triangles triangles;

protected:
	void onButtonClick(size_t index);
	bool onKeyPress(GdkEventKey* key_event);

public:
	Frame();

	Frame(const Frame &obj) = delete;
	Frame(Frame &&obj) = delete;
	Frame& operator=(const Frame &obj) = delete;
	Frame& operator=(Frame &&obj) = delete;

	void placeLeftTriangle(size_t index) override;
	void placeBlank(size_t index) override;
	void placeRightTriangle(size_t index) override;
	void swapCells(size_t l, size_t r) override;

	~Frame() override;
};

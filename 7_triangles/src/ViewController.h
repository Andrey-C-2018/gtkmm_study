#pragma once
#include <vector>
#include <gtkmm/window.h>
#include <gtkmm/toolbutton.h>
#include <gtkmm/hvbox.h>
#include "ICellsView.h"
#include "Interactor.h"

class ViewController : public Gtk::Window, public ICellsView {
	Gtk::HBox box;
	Glib::RefPtr<Gdk::Pixbuf> left, right, blank;
	std::vector<Gtk::Image> images;
	std::vector<Gtk::ToolButton> buttons;
	Interactor interactor;

protected:
	void onButtonClick(size_t index);
	bool onKeyPress(GdkEventKey* key_event);

public:
	ViewController();

	ViewController(const ViewController &obj) = delete;
	ViewController(ViewController &&obj) = delete;
	ViewController& operator=(const ViewController &obj) = delete;
	ViewController& operator=(ViewController &&obj) = delete;

	void placeLeftTriangle(size_t index) override;
	void placeBlank(size_t index) override;
	void placeRightTriangle(size_t index) override;
	void swapCells(size_t l, size_t r) override;

	~ViewController() override;
};

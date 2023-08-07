#pragma once
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>

class Frame : public Gtk::Window {
	Gtk::VBox box;

protected:
	void onNew();

public:
	Frame();

	Frame(const Frame &obj) = delete;
	Frame(Frame &&obj) = default;
	Frame& operator=(const Frame &obj) = delete;
	Frame& operator=(Frame &&obj) = default;

	virtual ~Frame(); 
};

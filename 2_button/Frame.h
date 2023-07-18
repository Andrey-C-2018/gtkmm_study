#pragma once
#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Frame : public Gtk::Window {
	Gtk::Button button;

protected:
	void onButtonClicked();

public:
	Frame();

	Frame(const Frame &obj) = delete;
	Frame(Frame &&obj) = default;
	Frame& operator=(const Frame &obj) = delete;
	Frame& operator=(Frame &&obj) = default;

	virtual ~Frame(); 
};

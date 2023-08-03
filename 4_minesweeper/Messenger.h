#pragma once
#include <gtkmm/button.h>

class Messenger final {
	Gtk::Button &output_widget;
	void setFontSize();

public:
	explicit Messenger(Gtk::Button &output_widget);

	Messenger(const Messenger &obj) = delete;
	Messenger(Messenger &&obj) = default;
	Messenger& operator=(const Messenger &obj) = delete;
	Messenger& operator=(Messenger &&obj) = delete;

	void onVictory();
	void onDefeat();
	void onReset();
};

#pragma once
#include "IMessenger.h"

class Messenger : public IMessenger {
	Gtk::Button &output_widget;

public:
	Messenger(Gtk::Button &output_widget);

	Messenger(const Messenger &obj) = delete;
	Messenger(Messenger &&obj) = default;
	Messenger& operator=(const Messenger &obj) = delete;
	Messenger& operator=(Messenger &&obj) = default;

	void sendMessage(const char *text) override;

	~Messenger() override;
};

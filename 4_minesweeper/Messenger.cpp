#include <gtkmm/messagedialog.h>
#include "Messenger.h"

Messenger::Messenger(Gtk::Widget &output_widget_) : \
						output_widget(output_widget_) { }

void Messenger::sendMessage(const char *text) {

	Gtk::MessageDialog dialog("OK", true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
	dialog.set_title("");
	dialog.set_message(text);
	dialog.set_default_response(Gtk::RESPONSE_OK);
	dialog.run();
}

Messenger::~Messenger() { }

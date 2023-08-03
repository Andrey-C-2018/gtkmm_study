#include <gtkmm/messagedialog.h>
#include "Messenger.h"

Messenger::Messenger(Gtk::Button &output_widget_) : \
						output_widget(output_widget_) { }

void Messenger::sendMessage(const char *text) {

	output_widget.set_label(text);
}

Messenger::~Messenger() { }

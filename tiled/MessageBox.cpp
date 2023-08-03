#include <gtkmm/messagedialog.h>
#include "MessageBox.h"

void MessageBox::showMessage(const char *title, const char *text) {

	Gtk::MessageDialog dialog("OK", true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
	dialog.set_title(title);
	dialog.set_message(text);
	dialog.set_default_response(Gtk::RESPONSE_OK);
	dialog.run();
}


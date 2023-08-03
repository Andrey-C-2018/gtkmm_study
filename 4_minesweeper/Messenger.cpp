#include "Messenger.h"

Messenger::Messenger(Gtk::Button &output_widget_) : \
						output_widget(output_widget_) {

	onReset();
}

void Messenger::onVictory() {

	output_widget.set_label(u8"\xF0\x9F\x98\x8E");
	setFontSize();
}

void Messenger::onDefeat() {

	output_widget.set_label(u8"\xF0\x9F\x98\xA9");
	setFontSize();
}

void Messenger::onReset() {

	output_widget.set_label(u8"\xF0\x9F\x98\x90");
	setFontSize();
}

void Messenger::setFontSize() {

	auto btn_label = output_widget.get_child();
	auto context = btn_label->get_pango_context();
	auto font = context->get_font_description();
	font.set_size(24 * PANGO_SCALE);
	context->set_font_description(font);
}

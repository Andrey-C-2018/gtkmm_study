#include <iostream>
#include <gdkmm/pixbuf.h>
#include <gtkmm/image.h>
#include "Frame.h"

Frame::Frame() {

	set_border_width(10);
	set_default_size(300, 50);
	set_title("Triangles");

	Frame::add(box);
	const size_t DEF_SIZE = 96;
	auto right_tr = Gdk::Pixbuf::create_from_resource("/res/right.png");
	right_tr = right_tr->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);
	auto left_tr = Gdk::Pixbuf::create_from_resource("/res/left.png");
	left_tr = left_tr->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);
	auto blank = Gdk::Pixbuf::create_from_resource("/res/blank.svg");
	blank = blank->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);

	size_t j = 0;
	for (size_t i = 0; i < TRIANGLES_COUNT; i++, j++) {
		tr_img[j].set(right_tr);
		buttons[i].set_icon_widget(tr_img[j]);
		box.pack_start(buttons[i], Gtk::PACK_SHRINK);
	}

	size_t k = 0;
	for (size_t i = TRIANGLES_COUNT; i < COUNT - TRIANGLES_COUNT; i++, k++) {
		blank_img[k].set(blank);
		buttons[i].set_icon_widget(blank_img[k]);
		box.pack_start(buttons[i], Gtk::PACK_SHRINK);
	}

	for (size_t i = COUNT - TRIANGLES_COUNT; i < COUNT; i++, j++) {
		tr_img[j].set(left_tr);
		buttons[i].set_icon_widget(tr_img[j]);
		box.pack_start(buttons[i], Gtk::PACK_SHRINK);
	}

	box.show();
	box.show_all_children();
}

Frame::~Frame() { }

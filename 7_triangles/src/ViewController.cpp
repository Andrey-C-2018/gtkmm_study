#include <cassert>
#include <gdkmm/pixbuf.h>
#include <gtkmm/image.h>
#include "ViewController.h"

constexpr size_t DEF_SIZE = 96;

ViewController::ViewController() : interactor(this) {

	set_border_width(10);
	set_default_size(300, 50);
	set_title("Triangles");

	signal_key_press_event().connect(sigc::mem_fun(*this, &ViewController::onKeyPress));

	ViewController::add(vbox);
	left = Gdk::Pixbuf::create_from_resource("/res/left.svg");
	right = Gdk::Pixbuf::create_from_resource("/res/right.svg");
	blank = Gdk::Pixbuf::create_from_resource("/res/blank.svg");
	left = left->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);
	right = right->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);
	blank = blank->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);

	vbox.pack_start(hbox, Gtk::PACK_SHRINK);
	size_t count = interactor.getCellsCount();
	buttons.resize(count);
	images.resize(count);
	for (size_t i = 0; i < count; i++) {
		buttons[i].set_icon_widget(images[i]);
		buttons[i].set_can_focus(false);
		hbox.pack_start(buttons[i], Gtk::PACK_SHRINK);
		buttons[i].signal_clicked().connect(sigc::bind<size_t>(
				sigc::mem_fun(*this, &ViewController::onButtonClick), i));
	}
	interactor.reset();

	vbox.pack_start(status_label, Gtk::PACK_SHRINK);
	vbox.show();
	vbox.show_all_children();
}

void ViewController::onButtonClick(size_t index) {

	assert (index < buttons.size());
	interactor.onCellClick(index);
}

void ViewController::placeLeftTriangle(size_t index) {

	assert (index < buttons.size());
	images[index].set(left);
}

void ViewController::placeBlank(size_t index) {

	assert (index < buttons.size());
	images[index].set(blank);
}

void ViewController::placeRightTriangle(size_t index) {

	assert (index < buttons.size());
	images[index].set(right);
}

void ViewController::swapCells(size_t l, size_t r) {

	assert (l < buttons.size());
	assert (r < buttons.size());

	auto lpix = images[l].get_pixbuf();
	auto rpix = images[r].get_pixbuf();
	images[l].set(rpix);
	images[r].set(lpix);
}

bool ViewController::onKeyPress(GdkEventKey* event) {

	switch (event->keyval) {
		case 'u': interactor.undo(); break;
		case 'r': interactor.reset(); break;
		case 'h': interactor.hint();
	}
	return true;
}

void ViewController::clearStatus() {

	status_label.set_label("");
}

void ViewController::setStatusCompleted() {

	status_label.set_label("Completed");
	status_label.override_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
}

void ViewController::setStatusStuck() {

	status_label.set_label("Stuck");
	status_label.override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
}

ViewController::~ViewController() = default;

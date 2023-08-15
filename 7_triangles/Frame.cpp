#include <cassert>
#include <gdkmm/pixbuf.h>
#include <gtkmm/image.h>
#include "Frame.h"

constexpr size_t DEF_SIZE = 96;

Frame::Frame() : triangles(this) {

	set_border_width(10);
	set_default_size(300, 50);
	set_title("Triangles");

	Frame::add(box);
	left = Gdk::Pixbuf::create_from_resource("/res/left.png");
	right = Gdk::Pixbuf::create_from_resource("/res/right.png");
	blank = Gdk::Pixbuf::create_from_resource("/res/blank.svg");
	left = left->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);
	right = right->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);
	blank = blank->scale_simple(DEF_SIZE, DEF_SIZE, Gdk::INTERP_BILINEAR);

	size_t count = triangles.getCellsCount();
	buttons.resize(count);
	images.resize(count);
	for (size_t i = 0; i < count; i++) {
		buttons[i].set_icon_widget(images[i]);
		box.pack_start(buttons[i], Gtk::PACK_SHRINK);
		buttons[i].signal_clicked().connect(sigc::bind<size_t>(
				sigc::mem_fun(*this, &Frame::onButtonClick), i));
	}

	triangles.reset();

	box.show();
	box.show_all_children();
}

void Frame::onButtonClick(size_t index) {

	assert (index < buttons.size());
	triangles.onCellClick(index);
}

void Frame::placeLeftTriangle(size_t index) {

	assert (index < buttons.size());
	images[index].set(left);
}

void Frame::placeBlank(size_t index) {

	assert (index < buttons.size());
	images[index].set(blank);
}

void Frame::placeRightTriangle(size_t index) {

	assert (index < buttons.size());
	images[index].set(right);
}

void Frame::swapCells(size_t l, size_t r) {

	assert (l < buttons.size());
	assert (r < buttons.size());

	auto lpix = images[l].get_pixbuf();
	auto rpix = images[r].get_pixbuf();
	images[l].set(rpix);
	images[r].set(lpix);
}

Frame::~Frame() = default;

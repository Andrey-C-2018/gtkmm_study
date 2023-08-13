#include <iostream>
#include <gdkmm/general.h>
#include "DrawingArea.h"

DrawingArea::DrawingArea() {

	try {
		pixbuf = Gdk::Pixbuf::create_from_resource("/images/bomb.png");

	} catch (const Glib::Error &e) {
		std::cerr << e.what();
	}

}

bool DrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

	Gdk::Cairo::set_source_pixbuf(cr, pixbuf);
	cr->paint();
	return true;
}

DrawingArea::~DrawingArea() { }

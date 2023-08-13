#include <iostream>
#include <gdkmm/general.h>
#include <giomm/file.h>
#include "DrawingArea.h"

DrawingArea::DrawingArea() {

	try {
		pixbuf = Gdk::Pixbuf::create_from_resource("/res/bomb.png");
		auto pi_res = Gio::File::create_for_uri("resource:///res/pi.txt");
		auto stream = pi_res->read();

		gchar buffer[30];
		size_t bytes_count = stream->read(buffer, 30);
		buffer[bytes_count] = '\0';
		pi = &buffer[0];

	} catch (const Glib::Error &e) {
		std::cerr << e.what();
	}

	font.set_family("Monospace");
	font.set_weight(Pango::WEIGHT_BOLD);
	font.set_size(PANGO_SCALE * 16);
}

bool DrawingArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {

	drawText(cr, 150, 200, pi);

	Gdk::Cairo::set_source_pixbuf(cr, pixbuf);
	cr->paint();
	return true;
}

void DrawingArea::drawText(const Cairo::RefPtr<Cairo::Context>& cr, \
							double x, double y, const std::string &text) {

	auto layout = create_pango_layout(text);
	layout->set_font_description(font);

	int text_width;
	int text_height;
	layout->get_pixel_size(text_width, text_height);

	cr->move_to(x - text_width / 2.0, y - text_height / 2.0);
	layout->show_in_cairo_context(cr);
}

DrawingArea::~DrawingArea() { }

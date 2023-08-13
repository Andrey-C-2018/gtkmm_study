#pragma once
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class DrawingArea : public Gtk::DrawingArea {
	Glib::RefPtr<Gdk::Pixbuf> pixbuf;	

protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

public:
	DrawingArea();

	DrawingArea(const DrawingArea &obj) = delete;
	DrawingArea(DrawingArea &&obj) = default;
	DrawingArea &operator=(const DrawingArea &obj) = delete;
	DrawingArea &operator=(DrawingArea &&obj) = default;

	virtual ~DrawingArea();
};

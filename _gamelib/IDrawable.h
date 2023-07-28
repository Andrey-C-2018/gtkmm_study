#pragma once
#include <gtkmm/drawingarea.h>

typedef Cairo::RefPtr<Cairo::Context> DrawingContext;

struct IDrawable {

	virtual bool draw(const DrawingContext &cr, \
						int screen_width, int screen_height) = 0;
};

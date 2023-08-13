#include "Frame.h"

Frame::Frame() {

	set_border_width(10);
	set_title("Resources test");

	add(area);
	area.show();
}

Frame::~Frame() { }

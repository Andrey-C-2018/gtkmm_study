#include "Frame.h"

Frame::Frame() {

	set_border_width(10);
	set_default_size(300, 300);
	set_title("Resources test");

	Frame::add(area);
	area.show();
}

Frame::~Frame() { }

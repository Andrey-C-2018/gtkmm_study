#include "Frame.h"
#include "EvtHandler.h"

Frame::Frame() {

    set_border_width(10);
    set_title("Drawing test");

	field.init(3, 3, Color(0, 0xff, 0), std::make_unique<EvtHandler>());
    Frame::add(field);
    field.show();
}

Frame::~Frame() { }

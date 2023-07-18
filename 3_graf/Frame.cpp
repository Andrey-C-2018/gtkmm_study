#include "Frame.h"
#include <iostream>

Frame::Frame() {

    set_border_width(10);
    set_title("Drawing test");

    add(area);
    area.show();
}

Frame::~Frame() { }

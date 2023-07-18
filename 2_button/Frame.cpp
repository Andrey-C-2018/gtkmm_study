#include "Frame.h"
#include <iostream>

Frame::Frame() : button("Ok") {

	set_border_width(10);
	button.signal_clicked().connect(sigc::mem_fun(*this, &Frame::onButtonClicked));
	add(button);
	button.show();
}

void Frame::onButtonClicked() {

	std::cout << "clicked" << std::endl;
}

Frame::~Frame() { }

#include "MainWnd.h"

MainWnd::MainWnd() {

    set_border_width(10);
    set_title("Moonlander");

    field.init(moon_lander);
}

MainWnd::~MainWnd() = default;

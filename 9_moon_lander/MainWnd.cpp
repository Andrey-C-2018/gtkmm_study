#include "MainWnd.h"

MainWnd::MainWnd() : moon_lander(std::make_shared<MoonLander>()) {

    set_border_width(10);
    set_title("Moonlander");
    setResizeConstraints();

    field.init(moon_lander);
    MainWnd::add(field);
    field.show();
}

void MainWnd::setResizeConstraints() {

    constexpr size_t DEF_MIN_WINDOW_HEIGHT = 300;
    constexpr double ratio = 0.9;

    Gdk::Display *gdk_display = Gdk::Display::get_default().get();
    Gdk::Screen *gdk_screen = gdk_display->get_default_screen().get();
    int base = std::min(gdk_screen->get_height(), gdk_screen->get_height());
    set_default_size((int)((double)(base - 200) * ratio), base - 200);

    Gdk::Geometry geometry;
    geometry.min_width = (int)(DEF_MIN_WINDOW_HEIGHT * ratio);
    geometry.min_height = DEF_MIN_WINDOW_HEIGHT;
    geometry.min_aspect = ratio;
    geometry.max_aspect = ratio;
    set_geometry_hints(*this, geometry, \
					Gdk::WindowHints::HINT_MIN_SIZE | Gdk::WindowHints::HINT_ASPECT);
}

MainWnd::~MainWnd() = default;

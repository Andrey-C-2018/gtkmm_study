#include <cassert>
#include "GameMainWnd.h"

GameMainWnd::GameMainWnd(const char *title, int width, int height) {

	assert (title);
    set_border_width(10);
    set_title(title);
	set_default_size(width, height);

	GameMainWnd::add(field);
    field.show();
}

GameMainWnd::~GameMainWnd() { }
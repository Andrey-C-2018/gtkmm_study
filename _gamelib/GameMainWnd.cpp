#include "GameMainWnd.h"

GameMainWnd::GameMainWnd() {

    set_border_width(10);
    set_title("Game wnd");

	GameMainWnd::add(field);
    field.show();
}

GameMainWnd::~GameMainWnd() { }
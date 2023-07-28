#include <gtkmm.h>
#include <_gamelib/GameMainWnd.h>
#include "MineSweeperEvtHandler.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "ua.ryzhany.minesweeper");
	GameMainWnd frame;
	frame.getGameField().init(std::make_unique<MineSweeperEvtHandler>());

	return app->run(frame);
}

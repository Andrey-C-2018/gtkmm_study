#include <gtkmm.h>
#include <tiled/GameMainWnd.h>
#include "MineSweeper.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "ua.ryzhany.minesweeper");
	GameMainWnd frame("Minesweeper", 600, 600);
	frame.getGameField().init(std::make_unique<MineSweeper>());

	return app->run(frame);
}

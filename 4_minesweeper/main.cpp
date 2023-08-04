#include <gtkmm.h>
#include "MainWnd.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "ua.ryzhany.minesweeper");
	MainWnd frame;

	return app->run(frame);
}

#include "MainWnd.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "ua.ryzhany.moonlander");
	MainWnd frame;

	return app->run(frame);
}

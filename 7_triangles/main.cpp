#include "src/ViewController.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.interactor");
	ViewController frame;

	return app->run(frame);
}

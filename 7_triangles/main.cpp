#include <gtkmm.h>
#include "Frame.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.triangles");
	Frame frame;

	return app->run(frame);
}

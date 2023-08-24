#include <iostream>
#include <gtkmm.h>
#include "CalcWnd.h"

int main(int argc, char *argv[]) {

	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.interactor");
	auto builder = Gtk::Builder::create();

	try {
		builder->add_from_resource("/res/window.glade");
	} catch (const Glib::FileError& ex) {
		std::cerr << "FileError: " << ex.what() << std::endl;
		return 1;
	} catch (const Glib::MarkupError& ex) {
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return 1;
	} catch(const Gtk::BuilderError& ex) {
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

	CalcWnd* wnd = nullptr;
	builder->get_widget_derived("CalcWnd", wnd);
	auto r = app->run(*wnd);

	delete wnd;
	return r;
}

#include "Frame.h"
#include <giomm/simpleactiongroup.h>
#include <gtkmm/builder.h>
#include <gtkmm/menubar.h>
#include <gtkmm/hvbox.h>
#include <iostream>

Frame::Frame() {

	set_border_width(10);
	auto actionGroup = Gio::SimpleActionGroup::create();
	actionGroup->add_action("new", sigc::mem_fun(*this, &Frame::onNew));
	insert_action_group("example", actionGroup);

	Glib::ustring ui_info =
			"<interface>"
			"  <menu id='menubar'>"
			"    <section>"
			"      <item>"
			"        <attribute name='label' translatable='yes'>New</attribute>"
			"        <attribute name='action'>example.new</attribute>"
			"      </item>"
			"    </section>"
			"  </menu>"
			"</interface>";

	auto builder = Gtk::Builder::create();
	try {
		builder->add_from_string(ui_info);
	} catch (const Glib::Error& e) {
		std::cerr << e.what() <<std::endl;
		return;
	}
	Glib::RefPtr<Glib::Object> object = builder->get_object("menubar");
	Glib::RefPtr<Gio::Menu> gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object);
	auto* pMenuBar = Gtk::make_managed<Gtk::MenuBar>(gmenu);

	Frame::add(box);
	box.pack_start(*pMenuBar, Gtk::PACK_SHRINK);
	show_all_children();
}

void Frame::onNew() {

	std::cout << "OK" << std::endl;
}

Frame::~Frame() { }

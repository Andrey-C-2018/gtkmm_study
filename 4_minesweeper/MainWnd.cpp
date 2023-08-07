#include <cassert>
#include <algorithm>
#include <iostream>
#include <giomm/simpleactiongroup.h>
#include <gtkmm/builder.h>
#include <gtkmm/menubar.h>
#include "MainWnd.h"

constexpr size_t DEF_MIN_WINDOW_HEIGHT = 300;

MainWnd::MainWnd() : horz_box(Gtk::ORIENTATION_HORIZONTAL, 5), \
					vert_box(Gtk::ORIENTATION_VERTICAL, 5), \
					counter_label(""), \
					restart_btn(""), \
					mine_sweeper(std::make_shared<MineSweeper>(this)), \
					mines_count(0), curr_ratio(0.0) {

    set_border_width(10);
    set_title("Minesweeper");
	set_position(Gtk::WIN_POS_MOUSE);

	setResizeConstraints(0.9, true);

	MainWnd::onReset();
	restart_btn.signal_clicked().connect(sigc::mem_fun(*this, \
												&MainWnd::onRestartBtnClicked));
	field.init(mine_sweeper);

	MainWnd::add(vert_box);
	initMenu();
	vert_box.pack_start(horz_box, Gtk::PACK_SHRINK);
	horz_box.pack_start(counter_label, Gtk::PACK_SHRINK);
	horz_box.pack_start(restart_btn, Gtk::PACK_EXPAND_WIDGET);
	vert_box.pack_start(field, Gtk::PACK_EXPAND_WIDGET);
	vert_box.show();
	vert_box.show_all_children();
}

void MainWnd::setResizeConstraints(double ratio, bool def_size) {

	if (abs(curr_ratio - ratio) <= 1e-7) return;
	curr_ratio = ratio;

	Gdk::Display *gdk_display = Gdk::Display::get_default().get();
	Gdk::Screen *gdk_screen = gdk_display->get_default_screen().get();
	int base = std::min(gdk_screen->get_height(), gdk_screen->get_height());
	if (def_size)
		set_default_size((int)((double)(base - 200) * ratio), base - 200);
	else
		set_size_request((int)((double)(base - 200) * ratio), base - 200);

	Gdk::Geometry geometry;
	geometry.min_width = (int)(DEF_MIN_WINDOW_HEIGHT * ratio);
	geometry.min_height = DEF_MIN_WINDOW_HEIGHT;
	geometry.min_aspect = ratio;
	geometry.max_aspect = ratio;
	set_geometry_hints(*this, geometry, \
					Gdk::WindowHints::HINT_MIN_SIZE | Gdk::WindowHints::HINT_ASPECT);
}

void MainWnd::initMenu() {

	auto actionGroup = Gio::SimpleActionGroup::create();
	actionGroup->add_action_radio_integer("size", \
							sigc::mem_fun(*this, &MainWnd::onSetFieldSize), -1);
	insert_action_group("mainmenu", actionGroup);

	Glib::ustring ui_info =
			"<interface>"
			"  <menu id='menubar'>"
			"    <submenu>"
			"      <attribute name='label' translatable='yes'>Setup</attribute>"
			"      <section>"
			"        <item>"
			"          <attribute name='label' translatable='yes'>8x8</attribute>"
			"          <attribute name='action'>mainmenu.size</attribute>"
			"          <attribute name='target' type='i'>0</attribute>"
			"        </item>"
			"      </section>"
			"      <section>"
			"        <item>"
			"          <attribute name='label' translatable='yes'>16x16</attribute>"
			"          <attribute name='action'>mainmenu.size</attribute>"
			"          <attribute name='target' type='i'>1</attribute>"
			"        </item>"
			"      </section>"
			"      <section>"
			"        <item>"
			"          <attribute name='label' translatable='yes'>30x16</attribute>"
			"          <attribute name='action'>mainmenu.size</attribute>"
			"          <attribute name='target' type='i'>2</attribute>"
			"        </item>"
			"      </section>"
			"    </submenu>"
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

	vert_box.pack_start(*pMenuBar, Gtk::PACK_SHRINK);
}

void MainWnd::onSetFieldSize(int size) {

	size_t cols, rows, mines;
	double ratio = 0.9;
	switch (size) {
		case SIZE8:
			cols = rows = 8;
			mines = 10;
			break;

		case SIZE16:
			cols = rows = 16;
			mines = 40;
			break;

		case SIZE30:
			cols = 30;
			rows = 16;
			mines = 99;
			ratio = 30.0 / 19.0;
			break;

		default:
			cols = rows = mines = 1;
	}
	setResizeConstraints(ratio);
	mine_sweeper->reset(cols, rows, mines);
}

void MainWnd::onRestartBtnClicked() {

	mine_sweeper->reset();
}

void MainWnd::onMinesPlaced(size_t mines_count_) {

	mines_count = mines_count_;
	counter_label.set_label(Glib::ustring::sprintf("%d/%d", 0, mines_count));
}

void MainWnd::onFlag(size_t flags_count) {

	assert (flags_count <= mines_count);
	counter_label.set_label(Glib::ustring::sprintf("%d/%d", flags_count, mines_count));
}

void MainWnd::onVictory() {

	setRestartBtnText(u8"\xF0\x9F\x98\x8E");
}

void MainWnd::onDefeat() {

	setRestartBtnText(u8"\xF0\x9F\x98\xA9");
}

void MainWnd::onReset() {

	setRestartBtnText(u8"\xF0\x9F\x98\x90");
	counter_label.set_label(Glib::ustring::sprintf("%d/%d", 0, mines_count));
}

MainWnd::~MainWnd() { }

#include <cassert>
#include "MainWnd.h"

MainWnd::MainWnd(const char *title, int width, int height) : \
					horz_box(Gtk::ORIENTATION_HORIZONTAL, 5), \
					vert_box(Gtk::ORIENTATION_VERTICAL, 5), \
					counter_label(""), \
					restart_btn(""), \
					mine_sweeper(std::make_shared<MineSweeper>(this)), \
					mines_count(0) {

	assert (title);
    set_border_width(10);
    set_title(title);
	set_default_size(width, height);

	MainWnd::onReset();
	restart_btn.signal_clicked().connect(sigc::mem_fun(*this, &MainWnd::onRestartBtnClicked));
	field.init(mine_sweeper);

	MainWnd::add(vert_box);
	vert_box.pack_start(horz_box, Gtk::PACK_SHRINK);
	horz_box.pack_start(counter_label, Gtk::PACK_SHRINK);
	horz_box.pack_start(restart_btn, Gtk::PACK_EXPAND_WIDGET);
	vert_box.pack_start(field, Gtk::PACK_EXPAND_WIDGET);
	vert_box.show();
	vert_box.show_all_children();
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
}

MainWnd::~MainWnd() { }

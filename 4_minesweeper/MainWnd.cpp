#include <cassert>
#include "MainWnd.h"

MainWnd::MainWnd(const char *title, int width, int height) : \
					mine_sweeper(std::make_shared<MineSweeper>()), \
					vert_box(Gtk::ORIENTATION_VERTICAL, 5), \
					restart_btn("Restart"){

	assert (title);
    set_border_width(10);
    set_title(title);
	set_default_size(width, height);

	restart_btn.signal_clicked().connect(sigc::mem_fun(*this, &MainWnd::onRestartBtnClicked));
	field.init(mine_sweeper);

	MainWnd::add(vert_box);
	vert_box.pack_start(restart_btn, Gtk::PACK_SHRINK);
	vert_box.pack_start(field, Gtk::PACK_EXPAND_WIDGET);
	vert_box.show();
	vert_box.show_all_children();
}

void MainWnd::onRestartBtnClicked() {

	mine_sweeper->reset();
}

MainWnd::~MainWnd() { }

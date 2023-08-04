#pragma once
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/button.h>
#include <tiled/GameField.h>
#include "MineSweeper.h"
#include "INotifier.h"

class MainWnd : public Gtk::Window, public INotifier {
	enum Constants {
		DEF_LABELS_FONT_SIZE = 24
	};
	Gtk::Box horz_box, vert_box;
	Gtk::Label counter_label;
	Gtk::Button restart_btn;
	std::shared_ptr<MineSweeper> mine_sweeper;
	GameField field;
	size_t mines_count;

	static inline void setFontSize(Widget *widget);
	inline void setRestartBtnText(const char *text);

protected:
	void onRestartBtnClicked();

public:
	MainWnd();

	MainWnd(const MainWnd &obj) = delete;
	MainWnd(MainWnd &&obj) = default;
	MainWnd& operator=(const MainWnd &obj) = delete;
	MainWnd& operator=(MainWnd &&obj) = default;

	void onVictory() override;
	void onDefeat() override;
	void onReset() override;

	void onMinesPlaced(size_t mines_count) override;

	void onFlag(size_t flags_count) override;

	virtual ~MainWnd();
};

//******************************************

void MainWnd::setFontSize(Widget *widget) {

	auto context = widget->get_pango_context();
	auto font = context->get_font_description();
	font.set_size(DEF_LABELS_FONT_SIZE * PANGO_SCALE);
	context->set_font_description(font);
}

void MainWnd::setRestartBtnText(const char *text) {

	restart_btn.set_label(text);
	setFontSize(restart_btn.get_child());
}

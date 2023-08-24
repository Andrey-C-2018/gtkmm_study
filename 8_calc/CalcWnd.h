#pragma once
#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include "Interactor.h"

class CalcWnd : public Gtk::Window {
	constexpr static size_t NUMBERS_COUNT = 10;
	constexpr static size_t DEF_FONT_SIZE = 18;

	Gtk::Entry *output;
	Gtk::Button *numeric_buttons[NUMBERS_COUNT]{};
	Gtk::Button *dot_button, *sign_button;
	Gtk::Button *plus_button;
	Gtk::Button *clear_button, *backspace_button, *eq_button;
	Interactor interactor;

	static void setFontSize(Widget *widget);

protected:
	void numericButtonClicked(size_t number);
	void operationButtonClicked();
	void dotButtonClicked();
	void signButtonClicked();
	void clearButtonClicked();
	void backspaceButtonClicked();
	void eqButtonClicked();

public:
	CalcWnd(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder);

	CalcWnd(const CalcWnd &obj) = delete;
	CalcWnd(CalcWnd &&obj) = default;
	CalcWnd& operator=(const CalcWnd &obj) = delete;
	CalcWnd& operator=(CalcWnd &&obj) = default;

	~CalcWnd() override;
};

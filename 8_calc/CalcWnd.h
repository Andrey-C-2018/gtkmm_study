#pragma once
#include <gtkmm/window.h>
#include <gtkmm/builder.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include "Calculator.h"

class CalcWnd : public Gtk::Window {
	constexpr static size_t NUMBERS_COUNT = 10;
	Gtk::Entry *output;
	Gtk::Button *numeric_buttons[NUMBERS_COUNT]{};
	Gtk::Button *plus_button;
	Gtk::Button *clear_button, *backspace_button, *eq_button;
	Calculator calc;

protected:
	void numericButtonClicked(size_t number);
	void operationButtonClicked();
	void clearButtonClicked();
	void backspaceButtonClicked();
	void dotButtonClicked();
	void eqButtonClicked();

public:
	CalcWnd(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder);

	CalcWnd(const CalcWnd &obj) = delete;
	CalcWnd(CalcWnd &&obj) = default;
	CalcWnd& operator=(const CalcWnd &obj) = delete;
	CalcWnd& operator=(CalcWnd &&obj) = default;

	~CalcWnd() override;
};

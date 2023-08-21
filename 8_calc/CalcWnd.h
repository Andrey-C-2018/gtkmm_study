#pragma once
#include <gtkmm/window.h>
#include <gtkmm/builder.h>

class CalcWnd : public Gtk::Window {
public:
	CalcWnd(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder);

	CalcWnd(const CalcWnd &obj) = delete;
	CalcWnd(CalcWnd &&obj) = default;
	CalcWnd& operator=(const CalcWnd &obj) = delete;
	CalcWnd& operator=(CalcWnd &&obj) = default;

	~CalcWnd() override;
};

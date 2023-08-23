#include <cassert>
#include "CalcWnd.h"

CalcWnd::CalcWnd(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder) : \
					Gtk::Window(obj), output(nullptr), plus_button(nullptr), \
					clear_button(nullptr), backspace_button(nullptr), eq_button(nullptr) {

	builder->get_widget("output", output);
	Glib::ustring buffer;
	for (size_t i = 0; i < NUMBERS_COUNT; i++) {
		buffer = (char) ('0' + i);
		builder->get_widget(buffer, numeric_buttons[i]);
		numeric_buttons[i]->signal_clicked().connect(sigc::bind<size_t>(
					sigc::mem_fun(*this, &CalcWnd::numericButtonClicked), i));
	}

	builder->get_widget("+", plus_button);
	plus_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::operationButtonClicked));
	builder->get_widget("<-", backspace_button);
	backspace_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::backspaceButtonClicked));
	builder->get_widget("C", clear_button);
	clear_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::clearButtonClicked));
	builder->get_widget("=", eq_button);
	eq_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::eqButtonClicked));
}

void CalcWnd::numericButtonClicked(size_t number) {

	assert (number < NUMBERS_COUNT);
	output->set_text(calc.addDigit((char)('0' + number)));
}

void CalcWnd::operationButtonClicked() {

	calc.addOperation(0);
}

void CalcWnd::backspaceButtonClicked() {

	output->set_text(calc.removeLast());
}

void CalcWnd::clearButtonClicked() {

	output->set_text(calc.clear());
}

void CalcWnd::eqButtonClicked() {

	output->set_text(calc.calculate());
}

CalcWnd::~CalcWnd() = default;

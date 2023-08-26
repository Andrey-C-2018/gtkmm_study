#include <cassert>
#include "CalcWnd.h"

constexpr const char *operation_ids[] = {"+", "-", "*"};

void CalcWnd::setFontSize(Widget *widget) {

	auto context = widget->get_pango_context();
	auto font = context->get_font_description();
	font.set_size(DEF_FONT_SIZE * PANGO_SCALE);
	context->set_font_description(font);
}

CalcWnd::CalcWnd(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder) : \
					Gtk::Window(obj), output(nullptr), \
					plus_button(nullptr), minus_button(nullptr), mult_button(nullptr), \
					dot_button(nullptr), sign_button(nullptr), \
					clear_button(nullptr), backspace_button(nullptr), eq_button(nullptr) {

	builder->get_widget("output", output);
	setFontSize(output);
	output->set_alignment(Gtk::ALIGN_END);
	output->set_text(interactor.clear());

	Glib::ustring buffer;
	for (size_t i = 0; i < NUMBERS_COUNT; i++) {
		buffer = (char) ('0' + i);
		builder->get_widget(buffer, numeric_buttons[i]);
		numeric_buttons[i]->signal_clicked().connect(sigc::bind<size_t>(
					sigc::mem_fun(*this, &CalcWnd::numericButtonClicked), i));
		setFontSize(numeric_buttons[i]->get_child());
	}

	Gtk::Button *operation_buttons[] = {plus_button, minus_button, mult_button};
	for (size_t i = 0; i < sizeof operation_ids / sizeof(const char*); i++) {
		builder->get_widget(operation_ids[i], operation_buttons[i]);
		setFontSize(operation_buttons[i]->get_child());
		operation_buttons[i]->signal_clicked().connect(sigc::bind<const char*>(
		sigc::mem_fun(*this, &CalcWnd::operationButtonClicked), operation_ids[i]));
	}
	builder->get_widget(".", dot_button);
	setFontSize(dot_button->get_child());
	dot_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::dotButtonClicked));
	builder->get_widget("+/-", sign_button);
	setFontSize(sign_button->get_child());
	sign_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::signButtonClicked));
	builder->get_widget("<-", backspace_button);
	setFontSize(backspace_button->get_child());
	backspace_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::backspaceButtonClicked));
	builder->get_widget("C", clear_button);
	setFontSize(clear_button->get_child());
	clear_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::clearButtonClicked));
	builder->get_widget("=", eq_button);
	setFontSize(eq_button->get_child());
	eq_button->signal_clicked().connect(sigc::mem_fun(*this, \
                                                        &CalcWnd::eqButtonClicked));
}

void CalcWnd::numericButtonClicked(size_t number) {

	assert (number < NUMBERS_COUNT);
	output->set_text(interactor.addDigit((char)('0' + number)));
}

void CalcWnd::dotButtonClicked() {

	output->set_text(interactor.addDecimalPoint());
}

void CalcWnd::signButtonClicked() {

	output->set_text(interactor.toggleSign());
}

void CalcWnd::operationButtonClicked(const char *op) {

	interactor.addOperation(op);
}

void CalcWnd::backspaceButtonClicked() {

	output->set_text(interactor.removeLast());
}

void CalcWnd::clearButtonClicked() {

	output->set_text(interactor.clear());
}

void CalcWnd::eqButtonClicked() {

	output->set_text(interactor.calculate());
}

CalcWnd::~CalcWnd() = default;

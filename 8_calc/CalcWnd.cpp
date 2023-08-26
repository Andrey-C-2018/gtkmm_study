#include <cassert>
#include "CalcWnd.h"

constexpr const char *operation_ids[] = {"+", "-", "*", "/"};

void CalcWnd::setFontSize(Widget *widget) {

	auto context = widget->get_pango_context();
	auto font = context->get_font_description();
	font.set_size(DEF_FONT_SIZE * PANGO_SCALE);
	context->set_font_description(font);
}

CalcWnd::CalcWnd(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder) : \
					Gtk::Window(obj), output(nullptr), \
					plus_button(nullptr), minus_button(nullptr), mult_button(nullptr), \
					div_button(nullptr), \
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

	Gtk::Button *operation_buttons[] = {plus_button, minus_button, mult_button, div_button};
	for (size_t i = 0; i < sizeof operation_ids / sizeof(const char*); i++) {
		builder->get_widget(operation_ids[i], operation_buttons[i]);
		setFontSize(operation_buttons[i]->get_child());
		operation_buttons[i]->signal_clicked().connect(sigc::bind<const char*>(
		sigc::mem_fun(*this, &CalcWnd::operationButtonClicked), operation_ids[i]));
	}

	typedef void (CalcWnd::*PEventHandler)();
	PEventHandler handlers[] = {&CalcWnd::dotButtonClicked, &CalcWnd::signButtonClicked, \
								&CalcWnd::backspaceButtonClicked, &CalcWnd::clearButtonClicked, \
								&CalcWnd::eqButtonClicked};
	Gtk::Button *control_buttons[] = {dot_button, sign_button, \
										backspace_button, clear_button, eq_button};
	const char *control_ids[] = {".", "+/-", "<-", "C", "="};
	for (size_t i = 0; i < sizeof control_buttons / sizeof(const char *); i++) {
		builder->get_widget(control_ids[i], control_buttons[i]);
		setFontSize(control_buttons[i]->get_child());
		control_buttons[i]->signal_clicked().connect(sigc::mem_fun(*this, handlers[i]));
	}
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

	try {
		interactor.addOperation(op);
	}
	catch (std::exception &e) {
		output->set_text(e.what());
	}
}

void CalcWnd::backspaceButtonClicked() {

	output->set_text(interactor.removeLast());
}

void CalcWnd::clearButtonClicked() {

	output->set_text(interactor.clear());
}

void CalcWnd::eqButtonClicked() {

	try {
		output->set_text(interactor.calculate());
	}
	catch (std::exception &e) {
		output->set_text(e.what());
	}
}

CalcWnd::~CalcWnd() = default;

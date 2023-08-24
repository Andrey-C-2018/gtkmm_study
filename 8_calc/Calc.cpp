#include "Calc.h"
#include "NullOperation.h"
#include "Plus.h"
#include "Number.h"

Calc::Calc() : null_op(std::make_shared<NullOperation>()), head_op(null_op) { }

bool Calc::empty() const {

	return head_op == null_op;
}

void Calc::addOperation(int id) {

	double l = head_op->calculate();
	head_op = std::make_shared<Plus>();
	head_op->addOperand(std::make_shared<Number>(l));
}

void Calc::addNumber(double num) {

	head_op->addOperand(std::make_shared<Number>(num));
}

double Calc::calculate() {

	double r = head_op->calculate();
	head_op->addOperand(std::make_shared<Number>(r));
	return r;
}

void Calc::reset() {

	head_op = null_op;
	null_op->reset();
}


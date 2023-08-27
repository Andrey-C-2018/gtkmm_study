#include <cassert>
#include "Calc.h"
#include "OperationsFactory.h"
#include "IOperation.h"

Calc::Calc() : op(nullptr), count(0), calculated(false) { }

void Calc::addNumber(mpf_class num) {

	assert (count < MAX_PARAMS_COUNT);
	params[count++] = std::move(num);
}

void Calc::addOperation(const char *op_code) {

	if (op && !calculated && count == MAX_PARAMS_COUNT) {
		params[0] = op->calculate(params, count);
		calculated = true;
	}

	op = OperationsFactory::getInstance()->getOperation(op_code);
	count = 1;
}

mpf_class Calc::calculate() {

	if (!op) return params[0];
	if (count <= 1)
		params[1] = std::move(params[0]);

	params[0] = op->calculate(params, count);
	calculated = true;

	count = MAX_PARAMS_COUNT;
	return params[0];
}

void Calc::reset() {

	op = nullptr;
	params[0] = params[1] = 0.0;
	count = 0;
	calculated = false;
}


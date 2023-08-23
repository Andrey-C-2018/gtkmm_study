#include <cassert>
#include "Calculator.h"
#include "Plus.h"
#include "Number.h"

Calculator::Calculator() : curr_num("0") { }

const std::string &Calculator::addDigit(char d) {

	assert ('0' <= d && d <= '9');
	if (curr_num == "0")
		curr_num = d;
	else
		curr_num += d;
	return curr_num;
}

const std::string &Calculator::addDecimalPoint() {

	curr_num += '.';
	return curr_num;
}

const std::string &Calculator::removeLast() {

	assert (curr_num.size() > 1);
	curr_num.erase(curr_num.size() - 1);
	if (curr_num.empty())
		curr_num = '0';
	return curr_num;
}

void Calculator::addOperation(int id) {

	// FIXME:
	assert (!head_op);
	head_op = std::make_shared<Plus>();
	if (curr_num.empty())
		curr_num += '0';

	double v = std::stod(curr_num);
	auto l = std::make_shared<Number>(v);
	head_op->addOperand(l);
	curr_num = '0';
}

std::string Calculator::calculate() {

	if (head_op) {
		double v = std::stod(curr_num);
		auto r = std::make_shared<Number>(v);
		head_op->addOperand(r);
		curr_num = std::to_string(head_op->calculate());
	}
	return curr_num;
}

const std::string &Calculator::toggleSign() {

	if (curr_num != "0") {
		assert(!curr_num.empty());
		if (curr_num[0] != '-')
			curr_num.insert(curr_num.begin(), '-');
		else
			curr_num.erase(0, 1);
	}
	return curr_num;
}

const std::string &Calculator::clear() {

	curr_num = '0';
	head_op.reset();
	return curr_num;
}

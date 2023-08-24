#include <cassert>
#include "Interactor.h"

const std::string zero("0");

Interactor::Interactor() = default;

const std::string &Interactor::addDigit(char d) {

	assert ('0' <= d && d <= '9');
	if (curr_num.empty() || curr_num == "0")
		curr_num = d;
	else
		curr_num += d;
	return curr_num;
}

const std::string &Interactor::addDecimalPoint() {

	if (!curr_num.empty() && curr_num.find('.') != std::string::npos)
		return curr_num;

	if (curr_num.empty()) curr_num = '0';
	curr_num += ',';
	return curr_num;
}

const std::string &Interactor::removeLast() {

	if (curr_num.empty()) return zero;

	curr_num.erase(curr_num.size() - 1);
	if (curr_num.empty()) return zero;
	return curr_num;
}

void Interactor::addOperation(int id) {

	if (!curr_num.empty())
		calc.addNumber(std::stod(curr_num));

	calc.addOperation(id);
	curr_num.clear();
}

std::string Interactor::calculate() {

	if (!curr_num.empty())
		calc.addNumber(std::stod(curr_num));

	curr_num.clear();
	return std::to_string(calc.calculate());
}

const std::string &Interactor::toggleSign() {

	if (!curr_num.empty()) {
		if (curr_num[0] != '-')
			curr_num.insert(curr_num.begin(), '-');
		else
			curr_num.erase(0, 1);

		return curr_num;
	}
	return zero;
}

const std::string &Interactor::clear() {

	curr_num.clear();
	calc.reset();
	return zero;
}

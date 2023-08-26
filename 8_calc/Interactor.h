#pragma once
#include <string>
#include "Calc.h"

class Interactor final {
	std::string curr_num;
	Calc calc;

public:
	Interactor();

	Interactor(const Interactor &obj) = default;
	Interactor(Interactor &&obj) = default;
	Interactor &operator=(const Interactor &obj) = default;
	Interactor &operator=(Interactor &&obj) = default;

	const std::string &addDigit(char d);
	const std::string &addDecimalPoint();
	const std::string &removeLast();

	void addOperation(const char *op_code);
	const std::string &toggleSign();
	std::string calculate();

	const std::string &clear();
};

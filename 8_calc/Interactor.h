#pragma once
#include <string>
#include <sstream>
#include "Calc.h"

class Interactor final {
	constexpr static size_t DEF_PRECISION = 11;
	std::string curr_num;
	Calc calc;
	std::ostringstream result_buffer;

public:
	Interactor();

	Interactor(const Interactor &obj) = delete;
	Interactor(Interactor &&obj) = default;
	Interactor &operator=(const Interactor &obj) = delete;
	Interactor &operator=(Interactor &&obj) = default;

	const std::string &addDigit(char d);
	const std::string &addDecimalPoint();
	const std::string &removeLast();

	void addOperation(const char *op_code);
	const std::string &toggleSign();
	std::string calculate();

	const std::string &clear();
};

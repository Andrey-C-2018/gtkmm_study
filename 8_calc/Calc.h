#pragma once
#include <cstddef>
//#include <gmp.h>

struct IOperation;

class Calc final {
	constexpr static size_t MAX_PARAMS_COUNT = 2;

	IOperation *op;
	double params[MAX_PARAMS_COUNT]{};
	size_t count;
	bool calculated;

public:
	Calc();

	Calc(const Calc &obj) = default;
	Calc(Calc &&obj) = default;
	Calc &operator=(const Calc &obj) = default;
	Calc &operator=(Calc &&obj) = default;

	void addNumber(double num);
	void addOperation(const char *op_code);
	double calculate();
	void reset();
};

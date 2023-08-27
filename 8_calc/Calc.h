#pragma once
#include <cstddef>
#include <gmpxx.h>

struct IOperation;

class Calc final {
	constexpr static size_t MAX_PARAMS_COUNT = 2;

	IOperation *op;
	mpf_class params[MAX_PARAMS_COUNT]{};
	size_t count;
	bool calculated;

public:
	Calc();

	Calc(const Calc &obj) = default;
	Calc(Calc &&obj) = default;
	Calc &operator=(const Calc &obj) = default;
	Calc &operator=(Calc &&obj) = default;

	void addNumber(mpf_class num);
	void addOperation(const char *op_code);
	mpf_class calculate();
	void reset();
};

#pragma once
#include <memory>

struct IOperation {

	virtual double calculate(const double *params, size_t count) = 0;
	virtual ~IOperation() = default;
};
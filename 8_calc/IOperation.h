#pragma once
#include <memory>
#include <gmpxx.h>

struct IOperation {

	virtual mpf_class calculate(const mpf_class *params, size_t count) = 0;
	virtual ~IOperation() = default;
};
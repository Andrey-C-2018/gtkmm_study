#pragma once
#include "IOperation.h"

class Plus : public IOperation {
public:
	double calculate(const double *params, size_t count) override;
	~Plus() override = default;
};

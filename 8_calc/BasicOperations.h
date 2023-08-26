#pragma once
#include "IOperation.h"

class Plus : public IOperation {
public:
	double calculate(const double *params, size_t count) override;
	~Plus() override = default;
};

class Minus : public IOperation {
public:
	double calculate(const double *params, size_t count) override;
	~Minus() override = default;
};

class Mult : public IOperation {
public:
	double calculate(const double *params, size_t count) override;
	~Mult() override = default;
};

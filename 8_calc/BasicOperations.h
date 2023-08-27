#pragma once
#include "IOperation.h"

class Plus : public IOperation {
public:
	mpf_class calculate(const mpf_class *params, size_t count) override;
	~Plus() override = default;
};

class Minus : public IOperation {
public:
	mpf_class calculate(const mpf_class *params, size_t count) override;
	~Minus() override = default;
};

class Mult : public IOperation {
public:
	mpf_class calculate(const mpf_class *params, size_t count) override;
	~Mult() override = default;
};

class Div : public IOperation {
public:
	mpf_class calculate(const mpf_class *params, size_t count) override;
	~Div() override = default;
};

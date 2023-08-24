#pragma once
#include "UnaryOperation.h"

class Number;

class NullOperation : public UnaryOperation {
	static std::shared_ptr<Number> zero;

public:
	int getId() const override;
	double calculate() override;
	void reset();

	~NullOperation() override = default;
};

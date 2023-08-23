#pragma once
#include "BinaryOperation.h"

class Plus : public BinaryOperation {
public:
	double calculate() override;
	int getId() const override;

	~Plus() override = default;
};

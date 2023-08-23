#pragma once
#include "ICalculable.h"

class Number : public ICalculable {
	double v;

public:
	explicit Number(double v);

	double calculate() override;

	~Number() override = default;
};

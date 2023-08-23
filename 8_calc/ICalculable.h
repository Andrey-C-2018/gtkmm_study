#pragma once

struct ICalculable {

	virtual double calculate() = 0;
	virtual ~ICalculable() = default;
};

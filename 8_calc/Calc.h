#pragma once
#include <memory>
//#include <gmp.h>

struct IOperation;
class NullOperation;

class Calc final {
	std::shared_ptr<NullOperation> null_op;
	std::shared_ptr<IOperation> head_op;

public:
	Calc();

	Calc(const Calc &obj) = default;
	Calc(Calc &&obj) = default;
	Calc &operator=(const Calc &obj) = default;
	Calc &operator=(Calc &&obj) = default;

	bool empty() const;
	void addOperation(int id);
	void addNumber(double num);
	double calculate();
	void reset();
};

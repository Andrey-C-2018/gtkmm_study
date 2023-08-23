#pragma once
#include "IOperation.h"

class BinaryOperation : public IOperation {
protected:
	std::shared_ptr<ICalculable> left, right;

public:
	void addOperand(std::shared_ptr<ICalculable> op) override;
	~BinaryOperation() override = default;
};

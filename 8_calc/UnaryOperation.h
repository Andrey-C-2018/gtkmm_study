#pragma once
#include "IOperation.h"

class UnaryOperation : public IOperation {
	std::shared_ptr<ICalculable> operand;

public:
	void addOperand(std::shared_ptr<ICalculable> op) override;
	~UnaryOperation() override = default;
};

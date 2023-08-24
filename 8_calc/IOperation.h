#pragma once
#include <memory>
#include "ICalculable.h"

struct IOperation : ICalculable {

	virtual int getId() const = 0;
	virtual void addOperand(std::shared_ptr<ICalculable> op) = 0;
	virtual void setLastOperand(std::shared_ptr<ICalculable> op) = 0;

	~IOperation() override = default;
};
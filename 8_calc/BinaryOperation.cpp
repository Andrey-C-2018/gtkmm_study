#include "BinaryOperation.h"

void BinaryOperation::addOperand(std::shared_ptr<ICalculable> op) {

	if (!left)
		left = op;
	else {
		if (right) left = op;
		else right = op;
	}
}

void BinaryOperation::setLastOperand(std::shared_ptr<ICalculable> op) {

	right = op;
}

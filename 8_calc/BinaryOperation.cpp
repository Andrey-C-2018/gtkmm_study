#include "BinaryOperation.h"

void BinaryOperation::addOperand(std::shared_ptr<ICalculable> op) {

	if (!left)
		left = op;
	else
		right = op;
}

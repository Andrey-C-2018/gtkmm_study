#include "UnaryOperation.h"

void UnaryOperation::addOperand(std::shared_ptr<ICalculable> op) {

	operand = op;
}

void UnaryOperation::setLastOperand(std::shared_ptr<ICalculable> op) {

	operand = op;
}

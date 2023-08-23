#include "UnaryOperation.h"

void UnaryOperation::addOperand(std::shared_ptr<ICalculable> op) {

	operand = op;
}

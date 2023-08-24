#include "NullOperation.h"
#include "Operations.h"
#include "Number.h"

std::shared_ptr<Number> NullOperation::zero = std::make_shared<Number>(0);

int NullOperation::getId() const {

	return NULL_OP;
}

double NullOperation::calculate() {

	return operand ? operand->calculate() : 0;
}

void NullOperation::reset() {

	UnaryOperation::addOperand(zero);
}

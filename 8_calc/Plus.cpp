#include <cassert>
#include "Plus.h"
#include "Operations.h"

int Plus::getId() const {

	return PLUS;
}

double Plus::calculate() {

	assert (left);
	return left->calculate() + (right ? right->calculate() : 0.0);
}

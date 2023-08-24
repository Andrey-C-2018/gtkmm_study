#include <cassert>
#include "Plus.h"
#include "Operations.h"

int Plus::getId() const {

	return PLUS;
}

double Plus::calculate() {

	return (left ? left->calculate() : 0.0) + (right ? right->calculate() : 0.0);
}

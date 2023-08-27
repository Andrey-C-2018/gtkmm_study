#include <cassert>
#include <stdexcept>
#include "BasicOperations.h"

mpf_class Plus::calculate(const mpf_class *params, size_t count) {

	assert (params);
	assert (count <= 2);
	return (count > 0 ? params[0] : 0.0) + (count > 1 ? params[1] : 0.0);
}

mpf_class Minus::calculate(const mpf_class *params, size_t count) {

	assert (params);
	assert (count <= 2);
	return (count > 0 ? params[0] : 0.0) - (count > 1 ? params[1] : 0.0);
}

mpf_class Mult::calculate(const mpf_class *params, size_t count) {

	assert (params);
	assert (count <= 2);
	return (count > 0 ? params[0] : 0.0) * (count > 1 ? params[1] : 1.0);
}

mpf_class Div::calculate(const mpf_class *params, size_t count) {

	assert (params);
	if (count < 2 || params[1] == 0.0)
		throw std::logic_error("div by zero");

	return params[0] / params[1];
}
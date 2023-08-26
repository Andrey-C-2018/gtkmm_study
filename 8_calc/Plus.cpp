#include <cassert>
#include "Plus.h"

double Plus::calculate(const double *params, size_t count) {

	assert (params);
	assert (count <= 2);
	return (count > 0 ? params[0] : 0.0) + (count > 1 ? params[1] : 0.0);
}

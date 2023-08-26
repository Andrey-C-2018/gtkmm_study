#include <cassert>
#include <cstring>
#include "OperationsFactory.h"
#include "BasicOperations.h"

OperationsFactory *OperationsFactory::inst = nullptr;

OperationsFactory *OperationsFactory::getInstance() {

	if (!inst) inst = new OperationsFactory();
	return inst;
}

OperationsFactory::OperationsFactory() {

	operations.emplace_back(std::make_unique<Plus>());
	operations.emplace_back(std::make_unique<Minus>());
	operations.emplace_back(std::make_unique<Mult>());

	const char codes[] = "+,-,*";
	char buffer[10];
	const char *prev = codes, *p;
	size_t index = 0;
	while (*prev != '\0' && (p = strchr(prev, ',')) != nullptr) {
		strncpy(buffer, prev, p - prev);
		op_codes[buffer] = index++;
		prev = p + 1;
	}
	assert (*prev != '\0');
	op_codes[prev] = index;
}

IOperation *OperationsFactory::getOperation(const char *op_code) {

	assert (op_code);
	assert (op_codes.find(op_code) != op_codes.end());
	return operations[op_codes[op_code]].get();
}

void OperationsFactory::destroy() {

	if (inst) delete inst;
	inst = nullptr;
}

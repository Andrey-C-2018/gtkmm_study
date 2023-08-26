#include <cassert>
#include "OperationsFactory.h"
#include "Plus.h"

OperationsFactory *OperationsFactory::inst = nullptr;

OperationsFactory *OperationsFactory::getInstance() {

	if (!inst) inst = new OperationsFactory();
	return inst;
}

OperationsFactory::OperationsFactory() {

	operations.emplace_back(std::make_unique<Plus>());

	op_codes["+"] = 0;
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

#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>

struct IOperation;

class OperationsFactory final {
	static OperationsFactory *inst;

	std::vector<std::unique_ptr<IOperation>> operations;
	std::map<std::string, size_t> op_codes;

	OperationsFactory();

public:
	static OperationsFactory *getInstance();
	IOperation *getOperation(const char *op_code);

	static void destroy();
};

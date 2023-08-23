#pragma once
#include <string>
#include <memory>
//#include <gmp.h>

struct ICalculable;
struct IOperation;

class Calculator final {
	std::shared_ptr<IOperation> head_op;
	std::string curr_num;

public:
	Calculator();

	Calculator(const Calculator &obj) = default;
	Calculator(Calculator &&obj) = default;
	Calculator &operator=(const Calculator &obj) = default;
	Calculator &operator=(Calculator &&obj) = default;

	const std::string &addDigit(char d);
	const std::string &addDecimalPoint();
	const std::string &removeLast();

	void addOperation(int id);
	const std::string &toggleSign();
	std::string calculate();

	const std::string &clear();
};

#pragma once
#include <cstddef>
#include <utility>
#include <memory>
#include "Field.h"

class Solver final {
	struct Node {
		Field field;
		size_t moves_count;
		Move rev_move;
		std::shared_ptr<const Node> prev;
	};
	typedef std::shared_ptr<Node> NodePtr;
	std::shared_ptr<const Node> curr;

public:
	Solver();

	Solver(const Solver &obj) = default;
	Solver(Solver &&obj) = default;
	Solver &operator=(const Solver &obj) = default;
	Solver &operator=(Solver &&obj) = default;

	bool solve(const Field &initial_field);
	Field getLastField() const;
	Move nextMove();
};

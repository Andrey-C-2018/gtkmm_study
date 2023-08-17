#pragma once
#include <cstddef>
#include <utility>
#include <memory>
#include "Field.h"

class Solver final {
	struct Node {
		Field field;
		size_t moves_count;
		std::pair<size_t, size_t> rev_move;
		std::shared_ptr<const Node> prev;

		inline bool operator<(const Node &obj) const {

			return field.distFromCompletion() + moves_count <
					obj.field.distFromCompletion() + obj.moves_count;
		}
	};
	std::shared_ptr<const Node> curr;

public:
	Solver();

	Solver(const Solver &obj) = default;
	Solver(Solver &&obj) = default;
	Solver &operator=(const Solver &obj) = default;
	Solver &operator=(Solver &&obj) = default;

	bool solve(const Field &initial_field);
	std::pair<size_t, size_t> getNextStep();
	static std::pair<size_t, size_t> finalStep();
};

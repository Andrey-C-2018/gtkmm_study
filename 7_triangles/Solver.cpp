#include "Solver.h"
#include <cassert>
#include <queue>

Solver::Solver() = default;

bool Solver::solve(const Field &initial_field) {

	std::priority_queue<std::shared_ptr<Node>> pq;
	Node initial_node{initial_field, 0, {0,0}};

	pq.emplace(std::make_shared<Node>(std::move(initial_node)));
	while (!pq.empty()) {
		std::shared_ptr<const Node> node = pq.top();

		if (node->field.completed()) {
			curr = node;
			return true;
		}
		pq.pop();

		for (size_t i = 0; i < node->field.size(); i++) {
			auto move = node->field.calcCellMove(i);
			if (move.first != move.second) {
				Node new_node{node->field, node->moves_count + 1, \
							move, node};
				new_node.field.makeMove(move);
				pq.emplace(std::make_shared<Node>(std::move(new_node)));
			}
		}
	}
	return false;
}

std::pair<size_t, size_t> Solver::getNextStep() {

	assert (curr);
	auto move = curr->rev_move;
	assert (move.first != move.second);

	curr = curr->prev;
	return move;
}

std::pair<size_t, size_t> Solver::finalStep() {

	return {0, 0};
}

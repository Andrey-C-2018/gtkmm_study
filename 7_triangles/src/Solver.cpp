#include "Solver.h"
#include <cassert>
#include <list>
#include <queue>

Solver::Solver() = default;

bool Solver::solve(const Field &initial_field) {

	auto comparator = [](const NodePtr &l, const NodePtr &r) {

		return l->field.distFromCompletion() + l->moves_count <
			   r->field.distFromCompletion() + r->moves_count;
	};
	std::priority_queue<NodePtr, std::vector<NodePtr>, decltype(comparator)> pq(comparator);
	Node initial_node{initial_field, 0, Move::createEmpty()};

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
			if (!move.empty()) {
				Node new_node{node->field, node->moves_count + 1, \
							move, node};

				assert (new_node.field.moveValid(move));
				new_node.field.makeMove(move);
				pq.emplace(std::make_shared<Node>(std::move(new_node)));
			}
		}
	}
	return false;
}

Field Solver::getLastField() const {

	assert (curr);
	return curr->field;
}

Move Solver::nextMove() {

	assert (curr);
	auto move = curr->rev_move;
	assert ((!curr->moves_count && move.empty() && !curr->prev) || \
				curr->moves_count && !move.empty() && curr->prev);

	curr = curr->prev;
	return move;
}

#pragma once
#include <cstddef>
#include <utility>
#include <memory>
#include <list>
#include "Field.h"

class Solver final {
	struct Node {
		Field field;
		size_t moves_count;
		Move rev_move;
		std::shared_ptr<const Node> prev;
	};
	typedef std::shared_ptr<Node> NodePtr;
	typedef std::shared_ptr<const Node> ConstNodePtr;

	std::list<Move> completed_seq;
	std::list<Move>::const_iterator pos;

	void createCompletedSequence(ConstNodePtr last);

public:
	Solver();

	Solver(const Solver &obj) = default;
	Solver(Solver &&obj) = default;
	Solver &operator=(const Solver &obj) = default;
	Solver &operator=(Solver &&obj) = default;

	bool solve(const Field &initial_field);
	inline bool solved() const;
	inline Move nextMove();
	inline void gotoPrevMove();
	inline bool atEnd() const;
	inline void reset();
};

//*****************************************

bool Solver::solved() const {

	return !completed_seq.empty();
}

Move Solver::nextMove() {

	if (completed_seq.empty() || pos == completed_seq.cend())
		return Move::createEmpty();

	Move move = *pos;
	++pos;
	return move;
}

void Solver::gotoPrevMove() {

	assert (pos != completed_seq.cbegin());
	--pos;
}

bool Solver::atEnd() const {

	return pos == completed_seq.cend();
}

void Solver::reset() {

	completed_seq.clear();
	pos = completed_seq.cend();
}

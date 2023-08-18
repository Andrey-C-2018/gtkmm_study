#include <algorithm>
#include "Field.h"

Field::Field() : total_size(DEF_SIZE), triangles_count(DEF_TRIANGLES) {

	reset();
}

Field::Field(size_t total_size_, size_t triangles_count_) : \
				total_size(total_size_), triangles_count(triangles_count_) {

	assert(2 * triangles_count < total_size);
	reset();
}

void Field::reset() {

	cells.reserve(total_size);

	cells.assign(triangles_count, LEFT);
	cells.insert(cells.end(), total_size - 2 * triangles_count, BLANK);
	cells.insert(cells.end(), triangles_count, RIGHT);
}

bool Field::completed() const {

	auto left_end = getLeftEnd();
	auto right_begin = getRightBegin();

	bool r = std::all_of(cells.cbegin(), left_end, \
						[](int i) -> bool { return i == RIGHT; });
	r = r && std::all_of(left_end, right_begin, \
						[](int i) -> bool { return i == BLANK; });
	assert (!r || r && std::all_of(right_begin, cells.cend(), \
						[](int i) -> bool { return i == LEFT; }));
	return r;
}

size_t Field::distFromCompletion() const {

	auto left_end = getLeftEnd();
	auto right_begin = getRightBegin();

	size_t d = 0;
	for (auto p = cells.cbegin(); p != left_end; ++p) {
		d += *p == BLANK;
		d += 2 * (*p == LEFT);
	}
	for (auto p = right_begin; p != cells.cend(); ++p) {
		d += *p == BLANK;
		d += 2 * (*p == RIGHT);
	}
	return d;
}

Move Field::calcCellMove(size_t index) const {

	assert (index < total_size);
	if (cells[index] == BLANK) return Move::createEmpty();

	if (cells[index] == LEFT) {
		if (index + 1 < total_size && cells[index + 1] == BLANK)
			return {index, index + 1};

		if (index + 2 < total_size && cells[index + 1] == RIGHT && cells[index + 2] == BLANK)
			return {index, index + 2};
	}

	if (cells[index] == RIGHT) {
		if (index > 0 && cells[index - 1] == BLANK)
			return {index - 1, index};

		if (index > 1 && cells[index - 1] == LEFT && cells[index - 2] == BLANK)
			return {index - 2, index};
	}
	return Move::createEmpty();
}

Move Field::tryMove(size_t index) {

	auto move = calcCellMove(index);
	if (!move.empty())
		std::swap(cells[move.left()], cells[move.right()]);

	return move;
}

void Field::makeMove(const Move &move) {

	assert (move.left() < cells.size());
	assert (move.right() < cells.size());
	std::swap(cells[move.left()], cells[move.right()]);
}

bool Field::moveValid(const Move &move) const {

	if (move.empty() || move.left() > move.right() || \
		move.left() >= cells.size() || move.right() >= cells.size() || \
		(cells[move.left()] == BLANK && cells[move.right()] == BLANK)) return false;

	return ((cells[move.left()] == LEFT && cells[move.right()] == BLANK) ||
			(cells[move.left()] == BLANK && cells[move.right()] == RIGHT));
}

std::string Field::toString() {

	std::string out;
	out.reserve(total_size);

	for (const auto &cell : cells) {
		switch (cell) {
			case LEFT: out += '>'; break;
			case BLANK: out += ' '; break;
			case RIGHT: out += '<';
			default: break;
		}
	}
	return out;
}
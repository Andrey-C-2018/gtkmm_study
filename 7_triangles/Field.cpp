#include <cassert>
#include <algorithm>
#include "Field.h"

Field::Field() {

	std::fill_n(cells, TRIANGLES_COUNT, LEFT);
	std::fill_n(cells + TRIANGLES_COUNT, TOTAL_SIZE - 2 * TRIANGLES_COUNT, BLANK);
	std::fill_n(cells + TOTAL_SIZE - TRIANGLES_COUNT, TRIANGLES_COUNT, RIGHT);
}

bool Field::completed() const {

	bool r = std::all_of(cells, cells + TRIANGLES_COUNT, \
						[](int i) -> bool { return i == RIGHT; });
	r = r && std::all_of(cells + TRIANGLES_COUNT, cells + TOTAL_SIZE - TRIANGLES_COUNT, \
						[](int i) -> bool { return i == BLANK; });
	assert (!r || r && std::all_of(cells + TOTAL_SIZE - TRIANGLES_COUNT, cells + TOTAL_SIZE, \
						[](int i) -> bool { return i == LEFT; }));
	return r;
}

size_t Field::distFromCompletion() const {

	size_t dist = std::count_if(cells, cells + TRIANGLES_COUNT, \
								[](int i) -> bool{ return i != RIGHT; });
	dist += std::count_if(cells + TRIANGLES_COUNT, cells + TOTAL_SIZE - TRIANGLES_COUNT, \
								[](int i) -> bool{ return i != BLANK; });
	dist += std::count_if(cells + TOTAL_SIZE - TRIANGLES_COUNT, cells + TOTAL_SIZE, \
								[](int i) -> bool{ return i != LEFT; });
	return dist;
}

std::pair<size_t, size_t> Field::calcCellMove(size_t index) const {

	assert (index < TOTAL_SIZE);
	if (cells[index] == BLANK) return {0, 0};

	if (cells[index] == LEFT) {
		if (index + 1 < TOTAL_SIZE && cells[index + 1] == BLANK)
			return {index, index + 1};

		if (index + 2 < TOTAL_SIZE && cells[index + 1] == RIGHT && cells[index + 2] == BLANK)
			return {index, index + 2};
	}

	if (cells[index] == RIGHT) {
		if (index > 0 && cells[index - 1] == BLANK)
			return {index - 1, index};

		if (index > 1 && cells[index - 1] == LEFT && cells[index - 2] == BLANK)
			return {index - 2, index};
	}
	return {0, 0};
}

std::pair<size_t, size_t> Field::makeMove(size_t index) {

	auto move = calcCellMove(index);
	if (move.first != move.second)
		std::swap(cells[move.first], cells[move.second]);

	return move;
}

void Field::makeMove(const std::pair<size_t, size_t> &m) {

	assert (m.first != m.second);
	std::swap(cells[m.first], cells[m.second]);
}
#pragma once
#include <cstddef>
#include <vector>
#include <string>
#include "Move.h"

class Field final {
	enum CellTypes {
		LEFT, BLANK, RIGHT
	};
	enum Defaults {
		DEF_SIZE = 7, DEF_TRIANGLES = 3
	};

	size_t total_size;
	size_t triangles_count;
	std::vector<int> cells;

	void init();
	inline std::vector<int>::const_iterator getLeftEnd() const;
	inline std::vector<int>::const_iterator getRightBegin() const;

public:
	Field();
	Field(size_t total_size, size_t triangles_count);

	Field(const Field& obj) = default;
	Field(Field&& obj) = default;
	Field &operator=(const Field& obj) = default;
	Field &operator=(Field&& obj) = default;

	bool completed() const;
	size_t distFromCompletion() const;
	inline size_t size() const;

	Move calcCellMove(size_t index) const;
	bool moveValid(const Move &move);
	Move makeMove(size_t index);
	void makeMove(const Move &move);

	std::string toString();
};

//*************************************************************

size_t Field::size() const {

	return total_size;
}

std::vector<int>::const_iterator Field::getLeftEnd() const {

	auto left_end = cells.begin();
	std::advance(left_end, triangles_count);
	return left_end;
}

std::vector<int>::const_iterator Field::getRightBegin() const {

	auto right_begin = cells.begin();
	std::advance(right_begin, cells.size() - triangles_count);
	return right_begin;
}

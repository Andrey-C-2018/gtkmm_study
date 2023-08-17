#pragma once
#include <cstddef>

class Field final {
	enum CellTypes {
		LEFT, BLANK, RIGHT
	};
	static constexpr size_t TOTAL_SIZE = 7;
	static constexpr size_t TRIANGLES_COUNT = 3;

	int cells[TOTAL_SIZE]{};

public:
	Field();

	Field(const Field& obj) = default;
	Field(Field&& obj) = default;
	Field &operator=(const Field& obj) = default;
	Field &operator=(Field&& obj) = default;

	bool completed() const;
	size_t distFromCompletion() const;
	inline size_t size() const;

	std::pair<size_t, size_t> calcCellMove(size_t index) const;
	std::pair<size_t, size_t> makeMove(size_t index);
	void makeMove(const std::pair<size_t, size_t> &m);
};

//*************************************************************

size_t Field::size() const {

	return TOTAL_SIZE;
}

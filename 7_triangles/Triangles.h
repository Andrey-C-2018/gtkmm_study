#pragma once
#include <cstddef>

struct ICellsView;

class Triangles {
	enum CellTypes {
		LEFT, BLANK, RIGHT
	};
	static constexpr size_t TOTAL_SIZE = 7;
	static constexpr size_t TRIANGLES_COUNT = 3;

	int cells[TOTAL_SIZE]{};
	ICellsView *view;

	void swapCells(size_t l, size_t r);

public:
	explicit Triangles(ICellsView *view_);

	Triangles(const Triangles& obj) = delete;
	Triangles(Triangles&& obj) = delete;
	Triangles &operator=(const Triangles& obj) = delete;
	Triangles &operator=(Triangles&& obj) = delete;

	void reset();
	inline size_t getCellsCount() const;
	void onCellClick(size_t index);
};

//*******************************************

size_t Triangles::getCellsCount() const {

	return TOTAL_SIZE;
}

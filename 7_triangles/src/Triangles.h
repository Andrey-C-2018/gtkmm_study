#pragma once
#include <cstddef>
#include <stack>

struct ICellsView;

class Triangles final {
	enum CellTypes {
		LEFT, BLANK, RIGHT
	};
	static constexpr size_t TOTAL_SIZE = 7;
	static constexpr size_t TRIANGLES_COUNT = 3;

	int cells[TOTAL_SIZE]{};
	ICellsView *view;
	std::stack<std::pair<size_t, size_t>> history;

	void swapCells(size_t l, size_t r);

public:
	explicit Triangles(ICellsView *view_);

	Triangles(const Triangles& obj) = delete;
	Triangles(Triangles&& obj) = delete;
	Triangles &operator=(const Triangles& obj) = delete;
	Triangles &operator=(Triangles&& obj) = delete;

	inline size_t getCellsCount() const;
	void onCellClick(size_t index);
	void undo();
	void reset();
};

//*******************************************

size_t Triangles::getCellsCount() const {

	return TOTAL_SIZE;
}

#include <cassert>
#include <algorithm>
#include "Triangles.h"
#include "ICellsView.h"

Triangles::Triangles(ICellsView *view_) : view(view_) {

	assert (view);
	assert (TOTAL_SIZE > TRIANGLES_COUNT);
	std::fill_n(cells, TOTAL_SIZE, BLANK);
}

void Triangles::onCellClick(size_t index) {

	assert (index < TOTAL_SIZE);
	if (cells[index] == BLANK) return;

	if (cells[index] == LEFT) {
		if (index + 1 < TOTAL_SIZE && cells[index + 1] == BLANK)
			swapCells(index, index + 1);
		else
			if (index + 2 < TOTAL_SIZE && cells[index + 1] == RIGHT && cells[index + 2] == BLANK)
				swapCells(index, index + 2);
	}

	if (cells[index] == RIGHT) {
		if (index > 0 && cells[index - 1] == BLANK)
			swapCells(index - 1, index);
		else
			if (index > 1 && cells[index - 1] == LEFT && cells[index - 2] == BLANK)
				swapCells(index - 2, index);
	}
}

void Triangles::swapCells(size_t l, size_t r) {

	view->swapCells(l, r);
	std::swap(cells[l], cells[r]);
	history.emplace(l, r);
}

void Triangles::undo() {

	if (!history.empty()) {
		auto move = history.top();
		history.pop();

		view->swapCells(move.first, move.second);
		std::swap(cells[move.first], cells[move.second]);
	}
}

void Triangles::reset() {

	std::fill_n(cells, TRIANGLES_COUNT, LEFT);
	for (size_t i = 0; i < TRIANGLES_COUNT; i++)
		view->placeLeftTriangle(i);

	std::fill_n(cells + TRIANGLES_COUNT, TOTAL_SIZE - 2 * TRIANGLES_COUNT, BLANK);
	for (size_t i = TRIANGLES_COUNT; i < TOTAL_SIZE - TRIANGLES_COUNT; i++)
		view->placeBlank(i);

	std::fill_n(cells + TOTAL_SIZE - TRIANGLES_COUNT, TRIANGLES_COUNT, RIGHT);
	for (size_t i = TOTAL_SIZE - TRIANGLES_COUNT; i < TOTAL_SIZE; i++)
		view->placeRightTriangle(i);
	history = {};
}
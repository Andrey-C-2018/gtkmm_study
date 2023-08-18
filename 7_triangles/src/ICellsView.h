#pragma once
#include <cstddef>

struct ICellsView {
	virtual void placeLeftTriangle(size_t index) = 0;
	virtual void placeBlank(size_t index) = 0;
	virtual void placeRightTriangle(size_t index) = 0;
	virtual void swapCells(size_t l, size_t r) = 0;

	virtual ~ICellsView() = default;
};
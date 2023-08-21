#pragma once
#include <cstddef>

struct IView {
	virtual void placeLeftTriangle(size_t index) = 0;
	virtual void placeBlank(size_t index) = 0;
	virtual void placeRightTriangle(size_t index) = 0;

	virtual void swapCells(size_t l, size_t r) = 0;

	virtual void clearStatus() = 0;
	virtual void setStatusCompleted() = 0;
	virtual void setStatusStuck() = 0;

	virtual ~IView() = default;
};
#pragma once
#include <stack>
#include "Field.h"
#include "Solver.h"

struct ICellsView;

class Interactor final {
	Field field;
	ICellsView *view;
	std::stack<Move> history;
	Solver solver;

public:
	explicit Interactor(ICellsView *view_);

	Interactor(const Interactor& obj) = delete;
	Interactor(Interactor&& obj) = delete;
	Interactor &operator=(const Interactor& obj) = delete;
	Interactor &operator=(Interactor&& obj) = delete;

	inline size_t getCellsCount() const;
	void onCellClick(size_t index);
	void undo();
	void hint();
	void reset();
};

//*******************************************

size_t Interactor::getCellsCount() const {

	return field.size();
}

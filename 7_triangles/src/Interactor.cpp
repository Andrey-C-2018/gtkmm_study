#include <cassert>
#include "Interactor.h"
#include "ICellsView.h"

Interactor::Interactor(ICellsView *view_) : view(view_) {

	assert (view);
}

void Interactor::onCellClick(size_t index) {

	assert (index < field.size());
	auto move = field.tryMove(index);
	if (!move.empty()) {
		view->swapCells(move.left(), move.right());
		history.push(move);

		if (solver.solved()) {
			auto move_hint = solver.nextMove();
			if (move != move_hint)
				solver.reset();
		}
	}
}

void Interactor::undo() {

	if (!history.empty()) {
		auto move = history.top();
		history.pop();

		view->swapCells(move.left(), move.right());
		field.makeMove(move);

		if (solver.solved()) {
			if (solver.atEnd())
				solver.reset();
			else
				solver.gotoPrevMove();
		}
	}
}

void Interactor::hint() {

	bool solved = solver.solved();
	if (!solved)
		solved = solver.solve(field);

	if (solved && !solver.atEnd()) {
		auto move = solver.nextMove();
		assert (field.moveValid(move));

		view->swapCells(move.left(), move.right());
		field.makeMove(move);
		history.push(move);
	}
}

void Interactor::reset() {

	field.reset();
	size_t field_size = field.size();
	for (size_t i = 0; i < field_size; i++) {
		switch (field.getCellAt(i)) {
			case Field::LEFT: view->placeLeftTriangle(i); break;
			case Field::BLANK: view->placeBlank(i); break;
			case Field::RIGHT: view->placeRightTriangle(i);
			default: break;
		}
	}
	history = {};
	solver.reset();
}
#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include <Solver.h>

void solvingSequence(Field &field);

SUITE(SolverTests) {

	TEST(solvable) {

		Field field(3, 1);
		Solver solver;

		CHECK(solver.solve(field));
		auto move = solver.getNextStep();
		CHECK(!move.empty());
	}

	TEST(getSolvingSequence3) {

		Field field(3, 1);
		std::cout << "3 cells:\n";
		solvingSequence(field);
	}

	TEST(getSolvingSequence5) {

		Field field(5, 2);
		std::cout << "5 cells:\n";
		solvingSequence(field);
	}

	TEST(getSolvingSequenceDefSize) {

		Field field;
		std::cout << "Def size:\n";
		solvingSequence(field);
	}
}

void solvingSequence(Field &field) {

	std::cout << field.toString() << std::endl;
	Solver solver;

	solver.solve(field);
	auto move = solver.getNextStep();
	while (!move.empty()) {
		CHECK(field.moveValid(move));
		field.makeMove(move);
		std::cout << field.toString() << std::endl;
		move = solver.getNextStep();
	}
	CHECK(field.completed());
}
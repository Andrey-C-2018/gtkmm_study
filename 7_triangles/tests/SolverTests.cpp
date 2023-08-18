#include <iostream>
#include <UnitTest++/UnitTest++.h>
#include <Solver.h>

void solvingSequence(Field &field);

SUITE(SolverTests) {

	TEST(solvable) {

		Field field(3, 1);
		Solver solver;

		CHECK(solver.solve(field));
		CHECK(!solver.nextMove().empty());
	}

	TEST(getSolvingSequence3) {

		Field field(3, 1);
		std::cout << "3 field:\n";
		solvingSequence(field);
	}

	TEST(getSolvingSequence5) {

		Field field(5, 2);
		std::cout << "5 field:\n";
		solvingSequence(field);
	}

	TEST(getSolvingSequenceDefSize) {

		Field field;
		std::cout << "Def size:\n";
		solvingSequence(field);
	}
}

void solvingSequence(Field &field) {

	Solver solver;
	CHECK(solver.solve(field));

	field = solver.getLastField();
	CHECK(field.completed());
	std::cout << field.toString() << std::endl;

	auto move = solver.nextMove();
	while (!move.empty()) {
		field.makeMove(move);
		std::cout << field.toString() << std::endl;
		move = solver.nextMove();
	}
}
#include <UnitTest++/UnitTest++.h>
#include <Field.h>

SUITE(FieldTests) {

	TEST(size3) {

		Field field(3, 1);
		CHECK_EQUAL(3, field.size());
	}

	TEST(size5) {

		Field field(5, 2);
		CHECK_EQUAL(5, field.size());
	}

	TEST(initialPosNotCompleted3) {

		Field field(3, 1);
		CHECK(!field.completed());
	}

	TEST(initialPosNotCompleted5) {

		Field field(5, 2);
		CHECK(!field.completed());
	}

	TEST(validMoves3) {

		Field field(3, 1);
		auto move = field.calcCellMove(0);
		CHECK_EQUAL(0, move.left());
		CHECK_EQUAL(1, move.right());
		field.makeMove(move);
		CHECK_EQUAL(" ><", field.toString());

		auto move2 = field.calcCellMove(2);
		CHECK_EQUAL(0, move2.left());
		CHECK_EQUAL(2, move2.right());
		field.makeMove(move2);
		CHECK_EQUAL("<> ", field.toString());
		CHECK(!field.completed());
	}

	TEST(invalidMoves5) {

		Field field(5, 2);
		auto move = field.calcCellMove(2);
		CHECK(move.empty());

		auto move2 = field.calcCellMove(0);
		CHECK(move2.empty());

		auto move3 = field.calcCellMove(4);
		CHECK(move3.empty());

		field.tryMove(1);
		field.tryMove(0);
		CHECK_EQUAL(" >><<", field.toString());
		for (size_t i = 1; i < 5; i++) {
			auto m = field.calcCellMove(2);
			CHECK(m.empty());
		}
	}

	TEST(completed3) {

		Field field(3, 1);
		CHECK_EQUAL("> <", field.toString());
		field.tryMove(0);
		CHECK_EQUAL(" ><", field.toString());
		field.tryMove(2);
		CHECK_EQUAL("<> ", field.toString());
		field.tryMove(1);
		CHECK_EQUAL("< >", field.toString());
		CHECK(field.completed());
	}

	TEST(completed5) {

		Field field(5, 2);
		CHECK_EQUAL(">> <<", field.toString());
		field.tryMove(1);
		CHECK_EQUAL("> ><<", field.toString());
		field.tryMove(3);
		CHECK_EQUAL("><> <", field.toString());
		field.tryMove(4);
		CHECK_EQUAL("><>< ", field.toString());
		field.tryMove(2);
		CHECK_EQUAL(">< <>", field.toString());
		field.tryMove(0);
		CHECK_EQUAL(" <><>", field.toString());
		field.tryMove(1);
		CHECK_EQUAL("< ><>", field.toString());
		field.tryMove(3);
		CHECK_EQUAL("<<> >", field.toString());
		field.tryMove(2);
		CHECK_EQUAL("<< >>", field.toString());
		CHECK(field.completed());
	}

	TEST(distanse3) {

		Field field(3, 1); // > <
		CHECK_EQUAL(4, field.distFromCompletion());
		field.tryMove(0); //  ><
		CHECK_EQUAL(3, field.distFromCompletion());
		field.tryMove(2); // <>
		CHECK_EQUAL(1, field.distFromCompletion());
		field.tryMove(1); // < >
		CHECK_EQUAL(0, field.distFromCompletion());
	}
}

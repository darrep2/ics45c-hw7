// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Array of int in int_array.hpp. It is graded: the
// autograder runs it against a correct Array and against several with one bug each. A test is
// worth something only when it passes on the correct Array and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the constructors, the copy and move
// operations, operator[] in and out of range, fill, and length.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "int_array.hpp"

TEST(IntArrayTests, DefaultArrayIsEmpty) {
    const Array a;
    EXPECT_EQ(a.length(), 0);
}

TEST(IntArrayTests, SizedArrayReportsItsLength) {
    const Array a{5};
    EXPECT_EQ(a.length(), 5);
}

// ADD YOUR TESTS HERE:

TEST(StudentIntArray, FillAllElement) {
	Array a{10};
	a.fill(7);
	for (int i = 0; i < a.length(); ++i) {
		EXPECT_EQ(a[i], 7);
	}
	a.fill(-3);
	for (int i = 0; i < a.length(); ++i) {
		EXPECT_EQ(a[i], -3);
	}
	EXPECT_EQ(a.length(), 10);
}

TEST(StudentIntArray, FillEmptyElement) {
	Array a;
	a.fill(5);
	EXPECT_EQ(a.length(), 0);
}

TEST(StudentIntArray, SubscriptAtEnd) {
	Array a{5};
	a.fill(0);
	a[0] = 6;
	a[3] = 7;
	EXPECT_EQ(a[0], 6);
	EXPECT_EQ(a[3], 7);
	EXPECT_EQ(a[1], 0);
}

TEST(StudentIntArray, SubscriptOutOfRange) {
	Array a{5};
	a.fill(1);
	EXPECT_THROW(a[1], std::string);
	EXPECT_THROW(a[-1], std::string);
	a[4] = 3;
	EXPECT_EQ(a[4], 3);
}

TEST(StudentIntArray, ConstSubscript) {
	Array a{3};
	a.fill(2);
	Array& c = a;
	EXPECT_EQ(c[0], 2);
	EXPECT_EQ(c[2], 2);
	EXPECT_ANY_THROW(c[3]);
	EXPECT_ANY_THROW(c[-1]);
}

TEST(StudentIntArray, EmptyArray) {
	Array a;
	a.fill(5);
	EXPECT_EQ(a.length(), 0);
	EXPECT_THROW(a[0], std::string);
}

TEST(StudentIntArray, OnlyOneElement) {
	Array a{1};
	a.fill(8);
	EXPECT_EQ(a.length(), 1);
	EXPECT_EQ(a[0], 8);
	EXPECT_THROW(a[1], std::string);
	EXPECT_THROW(a[-1], std::string);
}

TEST(StudentIntArray, CopyConstructorIsDeep) {
	Array a{4};
	for (int i = 0; i < 4; ++i)
		a[i] = i + 1;
	Array b{a};
	EXPECT_EQ(b.length(), 4);
	for (int i = 0; i < 4; ++i) 
		EXPECT_EQ(b[i], i + 1);
	b.fill(50);
	for (int i = 0; i < 4; ++i) 
		EXPECT_EQ(a[i], i + 1);
}

TEST(StudentIntArray, CopyAssignmentIsDeep) {
	Array a{3};
	a.fill(2);
	Array b{5};
	b.fill(9);
	b = a;
	EXPECT_EQ(b.length(), 3);
	for (int i = 0; i < 3; ++i) 
		EXPECT_EQ(b[i], 2);
	b[1] = 77;
	EXPECT_EQ(a[1], 2);
}

TEST(StudentIntArray, MoveConstructorWorks) {
	Array a{3};
	a[0] = 5;
	a[1] = 6;
	a[2] = 7;
	Array b{std::move(a)};
	EXPECT_EQ(b.length(), 3);
	EXPECT_EQ(b[0], 5);
	EXPECT_EQ(b[2], 7);
}

TEST(StudentIntArray, MoveAssignmentWorks) {
	Array a{2};
	a[0] = 1;
	a[1] = 2;
	Array b{4};
	b.fill(0);
	b = std::move(a);
	EXPECT_EQ(b.length(), 2);
	EXPECT_EQ(b[0], 1);
	EXPECT_EQ(b[1], 2);
}

TEST(StudentIntArray, SwapLengthsAndContents) {
	Array a{2};
	a.fill(1);
	Array b{3};
	b.fill(2);
	using std::swap;
	swap(a, b);
	EXPECT_EQ(a.length(), 3);
	EXPECT_EQ(b.length(), 2);
	EXPECT_EQ(a[2], 2);
	EXPECT_EQ(b[1], 1);
}

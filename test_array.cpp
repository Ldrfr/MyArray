#include "test_array.h"
#include "test_runner.cpp"

void TestOperator() {
	Array <int> a(3, 6);
	a.value_ = new int[6] {1, 2, 3, 214, 1253, 135};
	AssertEqual(a.value_[1], 2, "a.value_[1] != 2");
	AssertEqual(a.value_[5], 135, "a.value_[5] != 135, access to the last element doesn't work");
}

void TestPushBack() {
	// suppose that [new] adding to Array<int> zeros
	// size = amount of non-zero elements in array
	Array <int> a(2, 4);
	a.value_ = new int[4] {1, 2, 0, 0};
	a.PushBack(3);
	AssertEqual(a.value_[2], 3, "a.value_[2] != 3");
	AssertEqual(a.size_, (size_t)3, "a.size_ != 3");
	// when we need to expand array using SetSize
	Array <int> b(4, 4);
	b.value_ = new int[4] {1, 2, 3, 4};
	b.PushBack(5);
	AssertEqual(b.value_[4], 5, "b.value_[4] != 5 when it's end of array and after calling SetSize");
	AssertEqual(b.size_, (size_t)5, "size_ isn't correct when it's end of array and after calling SetSize");
	AssertEqual(b.maxsize_, (size_t)8, "maxsize_ isn't correct when it's end of array and after calling SetSize");
}

void TestInsert() {
	Array <int> b (3, 3);
	b.value_ = new int[12] {3, 8, 6};
	b.Insert(1, 5);
	AssertEqual(b.value_[1], 5, "incorrect element at position");
	AssertEqual(b.value_[3], 6, "last element after moving is not correct");
	Array <int> a (6, 12);
	a.value_ = new int[12] {7, 2, 3, 5, 8, 1};
	a.Insert(2, 4);
	AssertEqual(a.value_[2], 4, "incorrect element at position");
	AssertEqual(a.value_[6], 1, "last element after moving is not correct");
}

void TestRemove() {
	Array <int> a (4, 4);
	a.value_ = new int[4] {3, 5, 8, 6};
	a.Remove(1);
	AssertEqual(a.value_[1], 8, "incorrect element at removing position");
	AssertEqual(a.value_[2], 6, "last element after moving is not correct");
	AssertEqual(a.size_, (size_t)3, "size after removing wasn't decreased");
}


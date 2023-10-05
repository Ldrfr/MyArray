#include "test_array.cpp"

int main() {
	TestRunner tr;
	tr.RunTest(TestOperator, "TestOperator");
	tr.RunTest(TestPushBack, "TestPushBack");
	tr.RunTest(TestInsert, "TestInsert");
	tr.RunTest(TestRemove, "TestRemove");
	return 0;
}

#include "array.h"

template<class T, class U>
void AssertEqual(const T& t, const U& u, const char* hint) {
	if (t != u) {
		char message[256]; // if add something after strncpy added '0' it will not be overwritten?
		const char tmp1[19] = "Assertion failed: "; // 18 characters with '0' at the end
		strncpy(message, tmp1, 18); // '0' isn't added
		strncpy(message, hint, 100);
		throw Exception(EC_FUNCTION, message);
	}
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const char *test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (Exception &e) {
			++fail_count;
			cerr << test_name << " fail: " << e.GetMessage() << "\n";
		}
	}
	
	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

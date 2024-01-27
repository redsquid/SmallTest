# SmallTest

SmallTest is a simplified single-header library for unit testing. If you're going to create
small programm likes "HelloWorld.cpp" :) using the TDD approach and don't want to use large
framework likes gtest - SmallTest is what you need.

0. Include SmallTest.h
1. Create namespace for unit test
2. Add SMALLTEST macro with name of unit test (this namespace must contains only one SMALLTEST)
3. Add tests using TEST macro with name of test case
4. Add SMALLTEST_RUN macro in main for test execution

Example:

#include "SmallTest.h"

namespace mytesting {

	SMALLTEST("MyTesting")
	
	const int N = 1;
	const int M = 2;

	TEST(test1) {
		int n = 1;
		int m = 2;
		smalltest::assertion::equals(n, N);
		smalltest::assertion::equals(m, M);
	}

	TEST(test2) {
		smalltest::assertion::equals(N, M);
	}
}

int main() {
	SMALLTEST_RUN
	return 0;
}

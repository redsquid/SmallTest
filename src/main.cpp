
#include "Tests.hpp"
#include "Assertion.hpp"
#include "Macros.hpp"

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

	TEST(test3) {
		double a = 0.1;
		double b = 0.2;
		smalltest::assertion::equals(a, b);
	}

	TEST(test4) {
		double a = 0.01;
		double b = 0.02;
		smalltest::assertion::equals(a, b, 0.1);
	}

}


namespace yourtesting {
	
	SMALLTEST("YourTesting")

	int N = 5;
	
	TEST(yourtest1) {
		smalltest::assertion::equals(5, N);
	}

	TEST(yourtest2) {
		smalltest::assertion::equals(1, N);
	}

}


int main() {
	SMALLTEST_RUN
	return 0;
}


#include <iostream>

#include "Test.h"
#include "TestSuite.h"
#include "Assertion.h"

class Testing : public smalltest::Test<Testing> {
public:
	Testing() :  Test("Testing", this) {
		registerTest("Test1", &Testing::test1);
		registerTest("Test2", &Testing::test2);		
	}

	void test1() const {
		int n = 0;
		int m = 1;
		smalltest::assertion::assertEquals(n, m);
	}

	void test2() const {
		int n = 1;
		int m = 1;
		smalltest::assertion::assertEquals(n, m);

	}
};

int main() {
	smalltest::TestSuite suite;
	suite.registerTest(new Testing());
	suite.runTests();

	return 0;
}


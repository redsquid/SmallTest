#include "TestSuite.h"

#include <iostream>

namespace smalltest {

TestSuite::TestSuite() {
}

TestSuite::~TestSuite() {
    for (auto test : tests_) {
       delete test;
    }
}

void TestSuite::registerTest(ITest* test) {
    tests_.insert(test);
}

void TestSuite::runTests() {
	for (auto& test : tests_) {
		std::vector<Result> res = test->test();
		write(test->getName(), res);
    }
}

void TestSuite::write(const std::string& name, const std::vector<Result>& results) {
	console_.write(name, results);
}

} //namespace smalltest


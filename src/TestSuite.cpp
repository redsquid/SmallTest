#include "TestSuite.h"

#include "Console.h"

namespace smalltest {

TestSuite TestSuite::suite;

TestSuite::TestSuite() :
	console_(new Console())	
{
}

TestSuite::~TestSuite() {
}

TestSuite& TestSuite::getInstance() {
	return suite;
}

void TestSuite::registerTest(std::shared_ptr<ITest> test) {
    tests_.insert(test);
}

void TestSuite::runTests() {
	std::vector<Result> result;
	for (auto& test : tests_) {
		std::vector<Result> r = test->test();
		write(r);
    }
}

void TestSuite::write(const std::vector<Result>& results) {
	for(auto& r : results) {
		console_->write(r);
	}
}

} //namespace smalltest


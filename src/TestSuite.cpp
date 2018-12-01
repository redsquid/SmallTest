#include "TestSuite.hpp"

#include "Console.hpp"

namespace smalltest {

TestSuite* TestSuite::suite = nullptr;

TestSuite::TestSuite() :
	console_(new Console())	
{
}

TestSuite::~TestSuite() {
}

TestSuite& TestSuite::instance() {
	if(suite == nullptr) {
		suite = new TestSuite();
	}
	return *suite;
}

void TestSuite::add(ITests* test) {
    tests_.insert(test);
}

void TestSuite::run() {
	std::vector<Result> result;
	for (auto& test : tests_) {
		std::vector<Result> r = test->run();
		write(r);
    }
}

void TestSuite::write(const std::vector<Result>& results) {
	for(auto& r : results) {
		console_->write(r);
	}
}

} //namespace smalltest


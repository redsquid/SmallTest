#include "Tests.hpp"

namespace smalltest {

Tests::Tests(std::string name) :
	name_(name) 
{
}

Tests::~Tests() {
}

std::vector<Result> Tests::run() {
	std::vector<Result> results;
	for(auto& p : tests) {
		try {
			(*p.second)();
			results.push_back(Result::success(name_, p.first));
		} catch(TestException e) {
			results.push_back(Result::fail(name_, p.first, e.getMessage()));
		}
	}
	return results;
}

void Tests::add(std::string name, void (*test)()) {
	std::pair<std::string, void(*)()> p(name, test);
	tests.push_back(p);
}

std::string Tests::name() {
	return name_;
}

} //namespace smalltest


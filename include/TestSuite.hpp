#pragma once

#include "ITests.hpp"
#include "IOutput.hpp"
#include "Console.hpp"

#include <set>
#include <memory>

namespace smalltest {

class TestSuite {
public:
    virtual ~TestSuite() {}

    static TestSuite& instance() {
		if(suite == nullptr) {
			suite = new TestSuite();
		}
		return *suite;
	}
	
	void add(ITests* test) {
		tests_.insert(test);
	}
	
	void run() {
		std::vector<Result> result;
		for (auto& test : tests_) {
			std::vector<Result> r = test->run();
			write(r);
		}
	}

private:
	TestSuite() : console_(new Console()) {}
	
	void write(const std::vector<Result>& results) {
		for(auto& r : results) {
			console_->write(r);
		}
	}
    
	static TestSuite* suite;
	
	std::set<ITests*> tests_;
	
	std::unique_ptr<IOutput> console_;
};

TestSuite* TestSuite::suite = nullptr;

} // namespace smalltest


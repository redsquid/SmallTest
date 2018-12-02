#pragma once

#include "ITests.hpp"
#include "TestException.hpp"

#include <string>
#include <vector>

namespace smalltest {

class Tests : public ITests {
public:
    Tests(std::string name) :
		name_(name) 
	{
	}

	virtual ~Tests() {}

	std::vector<Result> run() override {
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

	void add(std::string name, void (*test)()) override {
		std::pair<std::string, void(*)()> p(name, test);
		tests.push_back(p);
	}
	
	std::string name() override {
		return name_;
	}

private:
	const std::string name_;
	
	std::vector<std::pair<std::string, void(*)()>> tests;
};

} //namespace smalltest


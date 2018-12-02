#pragma once

#include "Result.hpp"

#include <vector>

namespace smalltest {

class ITests {
public:
    virtual ~ITests() {}
    
	virtual std::vector<Result> run() = 0;
	
	virtual void add(std::string name, void (*test)()) = 0;
	
	virtual std::string name() = 0;
};

} //namespace smalltest


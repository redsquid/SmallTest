#ifndef ITESTS_H
#define ITESTS_H

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

}

#endif // ITESTS_H


#ifndef ITEST_H
#define ITEST_H

#include "Result.h"
#include <vector>

namespace smalltest {

class ITest {
public:
    virtual ~ITest() {}
    virtual std::vector<Result> test() = 0;
	virtual std::string getName() = 0;
};

}

#endif // ITEST_H


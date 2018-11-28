#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "ITest.h"
#include "IOutput.h"

#include <set>
#include <memory>

namespace smalltest {

class TestSuite {
public:
    TestSuite();
    virtual ~TestSuite();
    void registerTest(ITest* test);
    void runTests();

private:
	void write(const std::vector<Result>& results);
    std::set<ITest*> tests_;
	std::unique_ptr<IOutput> console_;
};

} // namespace smalltest

#endif // TESTSUITE_H

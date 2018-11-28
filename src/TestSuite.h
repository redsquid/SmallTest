#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "ITest.h"
#include "Console.h"

#include <set>

namespace smalltest {

class TestSuite {
public:
    TestSuite();
    virtual ~TestSuite();
    void registerTest(ITest* test);
    void runTests();

private:
	void write(const std::string& name, const std::vector<Result>& results);
    std::set<ITest*> tests_;
	Console console_;
};

} // namespace smalltest

#endif // TESTSUITE_H

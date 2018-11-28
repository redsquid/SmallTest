#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "ITest.h"
#include "IOutput.h"

#include <set>
#include <memory>

namespace smalltest {

class TestSuite {
public:
    virtual ~TestSuite();
    static TestSuite& getInstance();
	void registerTest(std::shared_ptr<ITest> test);
    void runTests();

private:
	TestSuite();
	void write(const std::vector<Result>& results);
    static TestSuite suite;
	std::set<std::shared_ptr<ITest> > tests_;
	std::unique_ptr<IOutput> console_;
};

} // namespace smalltest

#endif // TESTSUITE_H

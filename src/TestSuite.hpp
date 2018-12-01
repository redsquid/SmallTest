#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "ITests.hpp"
#include "IOutput.hpp"

#include <set>
#include <memory>

namespace smalltest {

class TestSuite {
public:
    virtual ~TestSuite();
    static TestSuite& instance();
	void add(ITests* test);
    void run();

private:
	TestSuite();
	void write(const std::vector<Result>& results);
    static TestSuite* suite;
	std::set<ITests*> tests_;
	std::unique_ptr<IOutput> console_;
};

} // namespace smalltest

#endif // TESTSUITE_H

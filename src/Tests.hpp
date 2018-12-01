#ifndef TESTS_H
#define TESTS_H

#include "ITests.hpp"
#include "TestException.hpp"

#include <string>
#include <vector>

namespace smalltest {

class Tests : public ITests {
public:
    Tests(std::string name);
	virtual ~Tests();
	std::vector<Result> run() override;
	void add(std::string name, void (*test)()) override;
	std::string name() override;

private:
	const std::string name_;
	std::vector<std::pair<std::string, void(*)()>> tests;
};

} //namespace smalltest

#endif // TESTS_H


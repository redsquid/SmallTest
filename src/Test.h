#ifndef TEST_H
#define TEST_H

#include "ITest.h"
#include "TestException.h"

#include <string>
#include <vector>

namespace smalltest {

template<typename T>
class Test : public ITest {
public:
    Test(std::string name, T* obj) : obj_(obj), name_(name) {}
	virtual ~Test() {}

	std::vector<Result> test() override {
		std::vector<Result> results;	
		for(auto& p : tests) {
			try {
				(obj_->*p.second)();
				results.push_back(Result::success(p.first));
			} catch(TestException e) {
				results.push_back(Result::fail(p.first, e.getMessage()));
			}
		}
		return results;
	}

	void registerTest(std::string name, void (T::*test)() const) {	
		std::pair<std::string, void((T::*)() const)> p(name, test);
		tests.push_back(p);
	}

	std::string getName() {
		return name_;
	}

private:
	const T* obj_;
	const std::string name_;
	std::vector<std::pair<std::string, void (T::*)() const> > tests;
};

} //namespace smalltest

#endif // TEST_H


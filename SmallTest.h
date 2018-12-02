#pragma once
/*
 *  SmallTest - A simplified C++ libreary for unit testing
 *  Generated: 2018-12-02 20:04:39.872853
 *  https://github.com/redsquid/SmallTest
 */



#include <string>

namespace smalltest {

class TestException {
public:
	TestException(std::string message) : message_(message) {}

	std::string getMessage() const {
		return message_;
	}

private:
	const std::string message_;
};

}


#include <sstream>
#include <cmath>

namespace smalltest::assertion {

template<typename T>
void equals(T expected, T value) {
	if(expected != value) {
		std::stringstream stream;
		stream << "assert equals failed expected: " << expected << " actual: " << value;
		throw TestException(stream.str());
	}
}

void equals(double expected, double value, double eps = 1e-6) {
	if(fabs(expected - value) >= eps) {
		std::stringstream stream;
		stream << "assert equals failed expected: " << expected << " actual: " << value << " eps: " << eps;
		throw TestException(stream.str());
	}
}

void fail() {
	throw TestException("assert fail");
}

void assert_true(bool value) {
	if(!value) {
		throw TestException("assert true is failed");
	}
}

void assert_false(bool value) {
	if(value) {
		throw TestException("assert false is failed");
	}
}

}


#include <string>

namespace smalltest {

class Result {
public:
	virtual ~Result() {}

	static Result success(const std::string& clazz, const std::string& name) {
		return Result(true, clazz, name, "success");
	}

	static Result fail(const std::string& clazz, const std::string& name, const std::string& message) {
		return Result(false, clazz, name, message);
	}

	bool isSuccess() const {
		return success_;
	}

	std::string getClassName() const {
		return clazz_;
	}

	std::string getTestName() const {
		return name_;
	}

	std::string getMessage() const {
		return message_;
	}

private:
	Result(bool success, const std::string clazz, const std::string& name, const std::string& message) :
		success_(success),
		clazz_(clazz),
		name_(name),
		message_(message)
	{
	}

	const bool success_;

	const std::string clazz_;

	const std::string name_;

	const std::string message_;
};

}


namespace smalltest {

class IOutput {
public:
	virtual ~IOutput() {}

	virtual void write(const Result& result) = 0;
};

}


#include <iostream>

namespace smalltest {

class Console : public IOutput {
public:
	Console() {};

	virtual ~Console() {};

	void write(const Result& r) override {
		if(r.isSuccess()) {
			std::cout << "[ OK ]\t " << r.getClassName() << ": " << r.getTestName() << std::endl;
		} else {
			std::cout << "[ FAIL ] " << r.getClassName() << ": " << r.getTestName() <<
				" couse: " << r.getMessage() << std::endl;
		}
	}
};

}
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

#include <set>
#include <memory>

namespace smalltest {

class TestSuite {
public:
    virtual ~TestSuite() {}

    static TestSuite& instance() {
		if(suite == nullptr) {
			suite = new TestSuite();
		}
		return *suite;
	}

	void add(ITests* test) {
		tests_.insert(test);
	}

	void run() {
		std::vector<Result> result;
		for (auto& test : tests_) {
			std::vector<Result> r = test->run();
			write(r);
		}
	}

private:
	TestSuite() : console_(new Console()) {}

	void write(const std::vector<Result>& results) {
		for(auto& r : results) {
			console_->write(r);
		}
	}

	static TestSuite* suite;

	std::set<ITests*> tests_;

	std::unique_ptr<IOutput> console_;
};

TestSuite* TestSuite::suite = nullptr;

}


namespace smalltest {

struct SuiteSupport {SuiteSupport(ITests& t) {smalltest::TestSuite::instance().add(&t);}};

struct TestsSupport {TestsSupport(smalltest::ITests& tests, std::string n, void(*t)()) {tests.add(n, t);}};

#define __SMALLTEST_PRFX __smalltest_
#define __SMALLTEST_TESTS __SMALLTEST_PRFX##tests
#define __SMALLTEST_SUITE_SPRT __SMALLTEST_PRFX##suitesupport_
#define __SMALLTEST_TESTS_SPRT __SMALLTEST_PRFX##testssupport_

#define SMALLTEST(name)\
	smalltest::Tests __SMALLTEST_TESTS(__SMALLTEST_QQ(name));\
	smalltest::SuiteSupport __SMALLTEST_SUITE_SPRT(__SMALLTEST_TESTS);

#define TEST(name)\
	void name();\
	smalltest::TestsSupport __SMALLTEST_TESTS_SPRT##name(__SMALLTEST_TESTS, __SMALLTEST_QQ(name), name);\
	void name()

#define SMALLTEST_RUN smalltest::TestSuite::instance().run();

#define __SMALLTEST_QQ(a) __SMALLTEST_PRE_QQ(a)
#define __SMALLTEST_PRE_QQ(a) #a


};
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

}



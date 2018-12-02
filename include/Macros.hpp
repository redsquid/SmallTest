#pragma once

#include "TestSuite.hpp"

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


}; //namespace smalltest


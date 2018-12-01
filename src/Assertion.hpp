#ifndef ASSERTION_H
#define ASSERTION_H

#include "TestException.hpp"

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

} //namespace smalltest::assertion

#endif // ASSERTION_H


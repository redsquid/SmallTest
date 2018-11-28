#ifndef ASSERTION_H
#define ASSERTION_H

#include "TestException.h"

#include <sstream>

namespace smalltest::assertion {

template<typename T>
static void assertEquals(T expected, T value) {
	if(expected != value) {
		std::stringstream stream;
		stream << "assertEquals failed expected: " << expected << " actual: " << value;
		throw TestException(stream.str());
	}	
}



} //namespace smalltest::assertion

#endif // ASSERTION_H


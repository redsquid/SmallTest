#ifndef IOUTPUT_H
#define IOUTPUT_H

#include "Result.hpp"

namespace smalltest {

class IOutput {
public:
	virtual ~IOutput() {}
	virtual void write(const Result& result) = 0;
};

} //namespace smalltest

#endif // IOUTPUT_H


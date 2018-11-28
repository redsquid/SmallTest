#ifndef IOUTPUT_H
#define IOUTPUT_H

#include "Result.h"

#include <vector>

namespace smalltest {

class IOutput {
public:
	virtual ~IOutput() {}
	virtual void write(const std::string& name, const std::vector<Result>& results) = 0;
};

} //namespace smalltest

#endif // IOUTPUT_H


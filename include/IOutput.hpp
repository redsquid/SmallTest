#pragma once

#include "Result.hpp"

namespace smalltest {

class IOutput {
public:
	virtual ~IOutput() {}
	
	virtual void write(const Result& result) = 0;
};

} //namespace smalltest


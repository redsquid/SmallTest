#pragma once

#include "IOutput.hpp"

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

} // namespace smalltest


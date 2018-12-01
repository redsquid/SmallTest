#include "Console.hpp"

#include <iostream>

namespace smalltest {
	
Console::Console() {
}

Console::~Console() {
}

void Console::write(const Result& r) {
	if(r.isSuccess()) {
		std::cout << "[ OK ]\t " << r.getClassName() << ": " << r.getTestName() << std::endl;
	} else {
		std::cout << "[ FAIL ] " << r.getClassName() << ": " << r.getTestName() << 
			" couse: " << r.getMessage() << std::endl;
	}
}

} // namespace smalltest


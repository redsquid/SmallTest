#include "Console.h"

#include <iostream>

namespace smalltest {
	
Console::Console() {
}

Console::~Console() {
}

void Console::write(const std::string& name, const std::vector<Result>& results) {
	writeHeader(name);
	for(auto& r : results) {	
		r.isSuccess() ? writeTestSuccess(r.getName()) : writeTestFail(r.getName(), r.getMessage());
	}
}

void Console::writeHeader(std::string name) {
	std::cout << "* Test: "<< name << std::endl;
}

void Console::writeTestSuccess(std::string name) {
	std::cout << "[ OK ]\t " << name << std::endl;
}

void Console::writeTestFail(std::string name, std::string message) {
	std::cout << "[ FAIL ] " << name << " couse: " << message << std::endl;
}

} // namespace smalltest


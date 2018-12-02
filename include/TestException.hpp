#pragma once

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

} // namespace smalltest


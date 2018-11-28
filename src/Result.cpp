#include "Result.h"

namespace smalltest {

Result::Result(bool success, std::string name, std::string message) :
	success_(success),
	name_(name),
	message_(message)
{
}

Result::~Result() {
}

Result Result::success(std::string name) {
	return Result(true, name, "success");
}

Result Result::fail(std::string name, std::string message) {
	return Result(false, name, message);
}

bool Result::isSuccess() const {
	return success_;
}

std::string Result::getName() const {
	return name_;
}

std::string Result::getMessage() const {
	return message_;
}

} // namespace smalltest


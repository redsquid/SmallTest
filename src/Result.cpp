#include "Result.hpp"

namespace smalltest {

Result::Result(bool success, const std::string clazz, const std::string& name, const std::string& message) :
	success_(success),
	clazz_(clazz),
	name_(name),
	message_(message)
{
}

Result::~Result() {
}

Result Result::success(const std::string& clazz, const std::string& name) {
	return Result(true, clazz, name, "success");
}

Result Result::fail(const std::string& clazz, const std::string& name, const std::string& message) {
	return Result(false, clazz, name, message);
}

bool Result::isSuccess() const {
	return success_;
}

std::string Result::getClassName() const {
	return clazz_;
}

std::string Result::getTestName() const {
	return name_;
}

std::string Result::getMessage() const {
	return message_;
}

} // namespace smalltest


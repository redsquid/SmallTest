#pragma once

#include <string>

namespace smalltest {

class Result {
public:
	virtual ~Result() {}

	static Result success(const std::string& clazz, const std::string& name) {
		return Result(true, clazz, name, "success");
	}

	static Result fail(const std::string& clazz, const std::string& name, const std::string& message) {
		return Result(false, clazz, name, message);
	}

	bool isSuccess() const {
		return success_;
	}

	std::string getClassName() const {
		return clazz_;
	}

	std::string getTestName() const {
		return name_;
	}
	
	std::string getMessage() const {
		return message_;
	}

private:
	Result(bool success, const std::string clazz, const std::string& name, const std::string& message) :
		success_(success),
		clazz_(clazz),
		name_(name),
		message_(message)
	{
	}

	const bool success_;
	
	const std::string clazz_;
	
	const std::string name_;
	
	const std::string message_;
};

} // namespace smalltest


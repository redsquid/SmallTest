#ifndef RESULT_H
#define RESULT_H

#include <string>

namespace smalltest {

class Result {
public:
	virtual ~Result();
	static Result success(const std::string& clazz, const std::string& name);
	static Result fail(const std::string& clazz, const std::string& name, const std::string& message);

	bool isSuccess() const;
	std::string getClassName() const;
	std::string getTestName() const;
	std::string getMessage() const;

private:
	Result(bool success, const std::string clazz, const std::string& name, const std::string& message);
	const bool success_;
	const std::string clazz_;
	const std::string name_;
	const std::string message_;

};

} // namespace smalltest

#endif // RESULT_H


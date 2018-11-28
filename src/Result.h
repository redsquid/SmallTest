#ifndef RESULT_H
#define RESULT_H

#include <string>

namespace smalltest {

class Result {
public:
	virtual ~Result();
	static Result success(std::string name);
	static Result fail(std::string name, std::string message);

	bool isSuccess() const;
	std::string getName() const;
	std::string getMessage() const;

private:
	Result(bool success, std::string name, std::string message);
	const bool success_;
	const std::string name_;
	const std::string message_;

};

} // namespace smalltest

#endif // RESULT_H


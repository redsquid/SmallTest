#ifndef CONSOLE_H
#define CONSOLE_H

#include "IOutput.h"

namespace smalltest {

class Console : public IOutput {
public:
	Console();
	virtual ~Console();
	void write(const std::string& name, const std::vector<Result>& results) override;

private:
	static void writeHeader(std::string name);
	static void writeTestSuccess(std::string name);
	static void writeTestFail(std::string name, std::string message);
};

} // namespace smalltest

#endif // RESULT_H


#ifndef CONSOLE_H
#define CONSOLE_H

#include "IOutput.h"

namespace smalltest {

class Console : public IOutput {
public:
	Console();
	virtual ~Console();
	void write(const Result& results) override;
};

} // namespace smalltest

#endif // RESULT_H


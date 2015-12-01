#include "npio.h"

#include "stdio.h"
#include <stdarg.h>

namespace npcore
{


	int NConsoleInput(const char *fmt, ...)
	{
		int ret;
		va_list args;
		va_start(args, fmt);
		ret = vscanf(fmt, args);
		va_end(args);
		return ret;
	}

	void NConsolePrint(const char * fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}
}
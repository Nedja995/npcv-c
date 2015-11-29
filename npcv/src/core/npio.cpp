#include "npio.h"

#include "stdio.h"
#include <stdarg.h>

namespace npcore
{
	void NConsolePrint(const char * fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}
}
#include "../../npstdlib/npstring.h"
#include <stdarg.h>
#include "stdio.h"

namespace npcore
{
	size_t string_length(char * string)
	{
		size_t ret = 0;
		for (; *(string + ret++) != '\0';);
		return ret - 1;
	}

	void sprintfN(char *buf, char *fmt, ...)
	{
		va_list va;
		va_start(va, fmt);
		vsprintf(buf, fmt, va);
		va_end(va);
	}
}
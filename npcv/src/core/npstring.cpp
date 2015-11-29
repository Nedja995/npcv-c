#include "npstring.h"
#include <stdarg.h>
#include "stdio.h"

namespace npcore
{
	char *strmakeN(const char * fmt, ...)
	{
		char *ret = (char*)mallocN(sizeof(char) * NP_MAX_STRING_BUFFER);
		*ret = '\0';
		va_list args;
		va_start(args, fmt);	
		sprintfN(ret, fmt, args);
		va_end(args);
		return ret;
	}


	size_t strnlenN(const char * string)
	{
		size_t ret = 0;
		for (; *(string + ret++) != '\0';);
		return ret - 1;
	}

	void sprintfN(char *buf,const char *fmt, ...)
	{
		va_list va;
		va_start(va, fmt);
		vsprintf(buf, fmt, va);
		va_end(va);
	}
}
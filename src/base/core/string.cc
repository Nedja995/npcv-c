#include "npstring.h"
#include "npmemory.h"
#include <stdarg.h>
#include <stdio.h>


	char *strmakeN(const char * fmt, ...)
	{
		char *ret =  (char*)mallocN(sizeof(char) * STRING_BUFFER);
		*ret = '\0';
		va_list args;
		va_start(args, fmt);	
		vsprintf(ret, fmt, args);
		va_end(args);
		return ret;
	}


	size_tt strnlenN(const char * string)
	{
		size_tt ret = 0;
		for (; *(string + ret++) != '\0';);
		return ret - 1;
	}

	void sprintfN(char *buf,const char *fmt, ...)
	{
		/*va_list va;
		va_start(va, fmt);
		vsprintf(buf, fmt, va);
		va_end(va);*/
	}

	void strreplaceN(char *string, char *from, char *to)
	{
		
		char *ch = string;
		int i = 0;
		int len = strnlenN(string);
		for (ch; i < len; i++) {
			if (*ch == *from) {
				memcpyN(ch, to, sizeof(char));
			}
			//else
			ch++;
		}


	}

	char *strappendN(const char *first, const char *second)
	{
		char *ret = (char*)mallocN(sizeof(char) * STRING_BUFFER);
		//sprintf(ret, "%s%s", first, second);
		return ret;
	}

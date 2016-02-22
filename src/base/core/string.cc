/*
* Copyright (c) 2016 Nedeljko Pejasinovic (nedjaunity@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include "npstring.h"
#include "npmemory.h"
#include "debug.h"
#include <stdarg.h>
#include <stdio.h>

#include <string.h>

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
	va_list va;
	va_start(va, fmt);
	vsprintf(buf, fmt, va);
	va_end(va);
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
	sprintf(ret, "%s%s", first, second);
	return ret;
}

char *stringDuplicate(const char * string)
{
	//npassert(string);

	return NULL;
}

int stringCompare(const char * string, const char * stringSecond)
{
	int i = 0;
	int ret = 0;
	if (strnlenN(string) != strnlenN(stringSecond))
	{
		return -1;
	}
	while (string + i != NULL)
	{
		if (*(string + i) == '\0' && *(stringSecond + i++) == '\0')
		{
			ret = 0;
			break;
		}
		if (*(string + i) != *(stringSecond + i++))
		{
			ret = -1;
			break;
		}
	}
	return ret;
}

const char *stringContains(const char * string, const char * sequence)
{
	return strstr(string, sequence);
}

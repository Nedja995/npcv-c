#ifndef __NPCORE_STRING__
#define __NPCORE_STRING__

#include "npstdlib.h"
//#  include <string.h>

namespace npcore
{
	//#define sprintfN(src, fmt, arg, arg2) sprintf(src, fmt, arg, arg2);
	//#define sprintfN(src, fmt, arg) sprintf(src, fmt, arg);
	//#define sprintfN(src, fmt) sprintf(src, fmt);

	size_t strnlen(char *string);
	//	char *
	//void sprintfN(char * dst, const char * formating, ...);
}
#endif

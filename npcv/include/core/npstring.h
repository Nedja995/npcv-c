#ifndef __NPCORE_STRING__
#define __NPCORE_STRING__

//#  include <npstring.h>
#include "datatypes.h"
#include "memory.h"

#define NP_MAX_STRING_BUFFER 1000

namespace npcore
{
	char *strmakeN(const char *fmt, ...);

	size_t strnlenN(const char *string);

	void sprintfN(char *buf, const char *fmt, ...);

	void strreplaceN(char *string, char *from, char *to);

}
#endif
#define string_alloc(length) (char *)mallocN(sizeof(char) * length + 1)
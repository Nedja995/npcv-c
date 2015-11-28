#ifndef __NPCORE_STRING__
#define __NPCORE_STRING__

//#  include <npstring.h>
#include "datatypes.h"
#include "memory.h"
namespace npcore
{
	char *string_create(size_t length);

	size_t string_length(char *string);

	void sprintfN(char *buf, char *fmt, ...);


}
#endif
#define string_alloc(length) (char *)mallocN(sizeof(char) * length + 1)
#include "../../npstdlib/string.h"
namespace npcore
{
	size_t strnlen(char * string)
	{
		size_t ret = 0;
		for (; *(string + ret++) != '\0';);
		return ret - 1;
	}
}
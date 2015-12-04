#include "ntime.h"
#include "memory.h"

#if defined _MSC_VER
#	include <windows.h>
#	include <wchar.h>
#	include <time.h>
#endif

namespace npcore {

	NTime *time_get_allocN()
	{
		NTime *ret = NULL;
#if defined _MSC_VER
			SYSTEMTIME lt;
		GetLocalTime(&lt);
		ret = (NTime*) duplicateN(&lt, sizeof(SYSTEMTIME));
#endif
		return ret;
	}


}
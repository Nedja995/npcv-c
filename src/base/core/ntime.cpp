#include "ntime.h"
#include "memory.h"
#include "debug.h"

#if defined _MSC_VER
#	include <windows.h>
#	include <wchar.h>

#endif
#	include <time.h>

namespace npcore {

	NTime *time_get_allocN()
	{
		NTime *ret = (NTime*)mallocN(sizeof(NTime));
		
#if defined _MSC_VER || defined __linux__
		time_t curtime;
		struct tm *loctime = (struct tm *)mallocN(sizeof(struct tm));

		/* Get the current time. */
		curtime = time(NULL);
	
		/* Convert it to local time representation. */
		errno_t error = -1;
#if defined _MSC_VER 
		error = localtime_s(loctime, &curtime);
#elif defined __linux__
		error = localtime_r(loctime, &curtime);
#endif
		if (error != 0) {
			NLogWarning("Can't get local time\n");
		}
		else {
			/* get values */
			ret->day = loctime->tm_mday;
			ret->hour = loctime->tm_hour;
			ret->milisecond = 0;
			ret->minute = loctime->tm_min;
			ret->month = loctime->tm_mon;
			ret->second = loctime->tm_sec;
			ret->year = 1900 + loctime->tm_year;
		}
		freeN(loctime);
#else
		NOT_IMPLEMENTED;
#endif
		return ret;
	}


}

#include "ntime.h"
#include "npmemory.h"
//#include "debug.h"
#include "npstring.h"

#if defined _MSC_VER
//#	include <windows.h>
//#	include <wchar.h>

#elif defined __linux__

#endif
#	include <time.h>

	/*
	 * @brief get local time
	 */
	NTime *time_get_allocN()
	{
		NTime *ret = (NTime*)mallocN(sizeof(NTime));
		int err = 0;
//		
#if defined _MSC_VER || defined __linux__
		time_t curtime;
		struct tm loctime;

		/* Get the current time. */
		curtime = time(&curtime);
	
		/* Convert it to local time representation. */		
#if defined _MSC_VER 
		err = localtime_s(&loctime, &curtime);
#elif defined __linux__
		localtime_r(&curtime,&loctime);
#endif
		if (err != 0) {
			//NLogWarning("Can't get local time\n");
		}
		else {
			/* get values */
			ret->day = loctime.tm_mday;
			ret->hour = loctime.tm_hour;
			ret->milisecond = 0;
			ret->minute = loctime.tm_min;
			ret->month = loctime.tm_mon;
			ret->second = loctime.tm_sec;
			ret->year = 1900 + loctime.tm_year;
		}
		//freeN(loctime);
#else
		NOT_IMPLEMENTED;
#endif
		return ret;
	}




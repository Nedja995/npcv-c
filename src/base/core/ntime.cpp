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
		struct tm *loctime;

		/* Get the current time. */
		curtime = time(NULL);

		/* Convert it to local time representation. */
		loctime = localtime(&curtime);

		ret->day = loctime->tm_mday;
		ret->hour = loctime->tm_hour;
		ret->milisecond = 0;
		ret->minute = loctime->tm_min;
		ret->month = loctime->tm_mon;
		ret->second = loctime->tm_sec;
		ret->year = 1900 + loctime->tm_year;
		
	//	freeN(loctime);
		
		/*Windows . old
		SYSTEMTIME lt;
		GetLocalTime(&lt);
		ret->day = (int)lt.wDay;
		ret->hour = (int)lt.wHour;
		ret->milisecond = (int)lt.wMilliseconds;
		ret->minute = (int)lt.wMinute;
		ret->month = (int)lt.wMonth;
		ret->second = (int)lt.wSecond;
		ret->year = (int)lt.wYear;*/
#else
		NOT_IMPLEMENTED;
#endif


		return ret;
	}


}

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




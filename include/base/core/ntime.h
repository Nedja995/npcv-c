#ifndef __NP_CORE_TIME_H__
#define __NP_CORE_TIME_H__

/**
*  \brief Basic times functions
*
*  \file ntime.h
*
*  \ingroup core
*
*  \author Nedeljko Pejasinovic
*
*/

#include "datatypes.h"
//#ifdef __cplusplus
//extern "C" {
//#endif
namespace npcore {
	//#define NULL 0

	/**
	 * @struct	NTime
	 * @brief	Time structure.
	 */
	struct NTime {
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
		int milisecond;
	};

	typedef struct NTime NTime;

	/**
	 * @brief	Constructor for Time struct.
	 *
	 * @return	null if it fails, else pointer to new Time struct.
	 */
	NTime *time_get_allocN();


	//#ifdef __cplusplus
	//}
	//#endif

}
#endif
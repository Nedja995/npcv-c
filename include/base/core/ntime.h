#ifndef __NP_CORE_TIME_H__
#define __NP_CORE_TIME_H__

#include "datatypes.h"
//#ifdef __cplusplus
//extern "C" {
//#endif
namespace npcore {
	//#define NULL 0


	struct NTime {
		ushort year;
		ushort month;
		ushort dayOfWeek;
		ushort day;
		ushort hour;
		ushort minute;
		ushort second;
		ushort milisecond;
	};
	typedef struct NTime NTime;

	NTime *time_get_allocN();


	//#ifdef __cplusplus
	//}
	//#endif

}
#endif
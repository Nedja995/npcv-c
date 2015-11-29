#ifndef __NSDK_STD_LIB_H__
#define __NSDK_STD_LIB_H__

#define _CRT_SECURE_NO_WARNINGS

#include "memory.h"

#include "debug.h"

#define NULL 0

namespace npcore {
	
	void NConsolePrint(const char *fmt, ...);

}



#endif

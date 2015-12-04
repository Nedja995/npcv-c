//
//TODO: tracing NCosolePrint and Input
//

#ifndef __NSDK_STD_LIB_H__
#define __NSDK_STD_LIB_H__

#define _CRT_SECURE_NO_WARNINGS


#define NULL 0

namespace npcore {
	
	void NConsolePrint(const char *fmt, ...);
	int NConsoleInput(const char *fmt, ...);
}



#endif

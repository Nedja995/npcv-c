#include "../debug.h"

#if defined _MSC_VER || defined __linux__
#	include "stdio.h"
#endif

namespace npcore {


	void Log(const char *text)
	{
		Log(text, LogLevel::INFO);
	}

		
	void Log(const char *text, LogLevel level)
	{
		if (level > logLevel) {
			return;
		}

		#if defined _MSC_VER || defined __linux__
			printf(text);
			//printf("\n");
		#endif
	}


}
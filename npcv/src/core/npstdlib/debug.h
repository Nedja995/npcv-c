#ifndef __NPCORE_DEBUG__
#define __NPCORE_DEBUG__

namespace npcore {

	typedef enum LogLevel {
		DISABLED = 0, //
		ERROR = 1, // critical error
		WARNING = 2, // warning

		INFO = 3, // only parametars debuging

		DEBUG = 4, // debug
		TRACE = 5 // every loged function
	} LogLevel;

	static LogLevel logLevel = LogLevel::TRACE;

	/*
	*
	*/
	void Log(const char *text, LogLevel level);
	void Log(const char *text);

}

#endif
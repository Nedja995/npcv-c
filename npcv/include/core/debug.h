
//
//	Preprocessor definitions:
//		_NP_TRACE			- write trace logs to file
//		_NP_TRACE_IMAGE		- trace image data
//

#ifndef __NPCORE_DEBUG__
#define __NPCORE_DEBUG__

#include "list.h"
#include "npstring.h"

namespace npcore {

	static bool DebugLogWrite = true;
	static char *dbg_default_TraceFile = "log.txt";
	static List *_debug_log_text_list;

	typedef enum LogLevel {
		DISABLED = 0, //
		ERROR = 1, // critical error
		WARNING = 2, // warning

		INFO = 3, // only parametars debuging

		DEBUG = 4, // debug
		TRACE = 5 // every loged function
	} LogLevel;

	static LogLevel logLevel = TRACE;


	//
	bool debug_initialize();
	//
	bool debug_exit();

	/*
	* Console Log
	*/
	void Log(const char *text, LogLevel level);
	void Log(const char *text);

	/*
	* Trace
	*/
	void NTrace(const char *msg, const char *traceListener);
	//default
	void NTrace(const char *msg);

#define NOT_IMPLEMENTED() Log("Called function with no implementation", npcore::DEBUG);


}

#endif
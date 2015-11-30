//TODO: add better logging level control during runtime (runtime log)
//TODO: add capabilities to set listener for called log (multi listeners)
//TODO: make loging system in new thread and write trace runtime

/*
* Logging must be enabled with both 
* preprocessor directives and				(optimization)
* same name variable in lower char			(runtime)
* 
* There are helper functions in format _does_<subject>_write_<object>()
*										(LOG or TRACE)	(CONSOLE or FILE)
*/
//
//	Preprocessor definitions:
//		_NP_LOG_DISABLED    - disable all debug logs call (optimisation)
//		_NP_LOG_OUT_FILE	- save debug logs to file
//		_NP_LOG_OUT_CONSOLE - write debug logs to console
//		_NP_TRACE_DISABLED	- disable all trace call (optimisation)
//		_NP_TRACE_OUT_FILE	- save trace to file
//		_NP_TRACE_OUT_CONSOLE - write trace to console
//

#ifndef __NPCORE_DEBUG__
#define __NPCORE_DEBUG__

//std
#include <stdarg.h>
#include "stdio.h"

#include "list.h"
#include "npstring.h"

#define DOES_WRITE_TRACE_CONSOLE

//
// Preprocessor
//
#define _NP_LOG_OUT_FILE 1
#define _NP_LOG_OUT_CONSOLE 1
#define _NP_TRACE_OUT_CONSOLE 1
#define _NP_TRACE_OUT_FILE 1


/*
*
* LOGGING
* 
*/

//
// Log levels
//
#define NP_FATAL 1  //
#define NP_ERROR 2  // 
#define NP_WARNING 3  //
#define NP_INFO 4  //
#define NP_DEBUG 5  //
#define NP_TRACE 6  //

//
// For implementation missing 
#define NOT_IMPLEMENTED() NLog("Called function with no implementation", NP_ERROR)

//
// LOG MACROS
//
#if _NP_LOG_DISABLED
//
// Empty function call when logging disabled
//
#define NLogTrace(NP_DEBUG, fmt_, ...)
#define NLogDebug(NP_DEBUG, fmt_, ...)
#define NLogWarning(NP_WARNING, fmt_, ...)
#define NLogError(fmt_, ...) 
#define NLogFatal(fmt_, ...) 
#define NLog(fmt_, ...)
#else
#define NLog(fmt_, ...)  \
	_np_log_fmt(NP_INFO, fmt_, __VA_ARGS__)
// LOG FATAL
#define NLogFatal(fmt_, ...)  \
	_np_log_fmt(NP_FATAL, fmt_, __VA_ARGS__)
// LOG ERROR
#define NLogError(fmt_, ...)  \
	_np_log_fmt(NP_ERROR, fmt_, __VA_ARGS__)
// LOG WARNING
#define NLogWarning(NP_WARNING, fmt_, ...)  \
	_np_log_fmt(fmt_, __VA_ARGS__)
// LOG DEBUG
#define NLogDebug(NP_DEBUG, fmt_, ...)  \
	_np_log_fmt(fmt_, __VA_ARGS__)
// LOG TRACE
#define NLogTrace(NP_DEBUG, fmt_, ...)  \
	_np_log_fmt(NP_TRACE, fmt_, __VA_ARGS__)
#endif


namespace npcore {
	//
	bool debug_initialize();
	//
	bool debug_exit();


	/*
	* Loging level flag
	*/
	typedef int NPLogLevel;

	//
	//Log variable
	static bool _np_log_disabled = false;
	static bool _np_log_out_file = true;
	static bool _np_log_out_console = true;
	
	//Trace variable
	static bool _np_trace_disabled = false;
	static bool _np_trace_out_file = true;
	static bool _np_trace_out_console = true;

	


	/*
	* LOG LEVEL
	* 
	*/
	static int logLevel = NP_TRACE;

	//
	// Default tracefile
	static char *_np_tracefile_default_path = "log.txt";

	// TODO add 
	// Store trace logs in list for writing at end
	static List *_np_trace_log_text_list;

	void _np_log(NPLogLevel level, const char* msg);

	void _np_log_fmt(NPLogLevel level,const char* fmt, ...);

	/*
	* Helpers
	*/
	bool _does_trace_with_console();
	bool _does_trace_with_file();
	bool _does_log_with_console();
	bool _does_log_with_file();

}










#endif
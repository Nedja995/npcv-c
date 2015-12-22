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
/**
*  @brief Debug and logging
*
*  Helpers for debuging 
*   And very configurable logging system
*
*  @file debug.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*  
*  
*
* @todo  Implement Trace Session via structure with runtime log flags
* @todo  Change LogLevel from macro to typedef 
* 		 (NP_FATAL, NP_ERROR,..)
* @todo  Add better logging level control during runtime
* @todo  Add capabilities to set listener for called log (multi listeners)
* @todo  Separate logging and trace in thread
*
*/


//std
//#include <stdarg.h>
//#include "stdio.h"

#include "list.h"
//#include "npstring.h"

#define DOES_WRITE_TRACE_CONSOLE

/**
 * @def	_NP_LOG_DISABLED
 * @brief	A macro that defines np log disabled.
 */
//#define _NP_LOG_DISABLED 1

/**@brief	If defined all logs will be writen to file at exit. */
#define _NP_LOG_OUT_FILE 1

/** @brief	If defined all logs will be printed at console. */
#define _NP_LOG_OUT_CONSOLE 1

/**@brief	If defined all trace and logs will printed at console. */
#define _NP_TRACE_OUT_CONSOLE 1

/** @brief	If defined all trace and logs will be writen to file at exit. */
#define _NP_TRACE_OUT_FILE 1


/**@brief	A macro that defines np fatal. */
#define NP_FATAL	1  

/**@brief	A macro that defines np error. */
#define NP_ERROR	2  

/**@brief	A macro that defines np warning.*/
#define NP_WARNING	3  

/** @brief	A macro that defines np information. */
#define NP_INFO		4  

/**@brief	A macro that defines np debug.*/
#define NP_DEBUG	5 

/** @brief	A macro that defines np trace.*/
#define NP_TRACE	6



/**
* @brief if disabled any log and trace functions
* 		 won't be called
*/
#if _NP_LOG_DISABLED
#define NLogTrace(fmt_, ...)
#define NLogDebug(fmt_, ...)
#define NLogWarning(fmt_, ...)
#define NLogError(fmt_, ...) 
#define NLogFatal(fmt_, ...) 
#define NLog(fmt_, ...)
#else

/**
 * @brief	Info log formated
 *
 * @param	fmt_	Describes the format to use.
 * @param	... 	Variable arguments providing additional information.
 */
#define NLog(fmt_, ...)  \
	_np_log_fmt(NP_INFO, fmt_, __VA_ARGS__)

/**
 * @brief	Fatal error log formated
 *
 * @param	fmt_	Describes the format to use.
 * @param	... 	Variable arguments providing additional information.
 */
#define NLogFatal(fmt_, ...)  \
	_np_log_fmt(NP_FATAL, fmt_, __VA_ARGS__)

/**
 * @brief	Error log formated
 *
 * @param	fmt_	Describes the format to use.
 * @param	... 	Variable arguments providing additional information.
 */
#define NLogError(fmt_, ...)  \
	_np_log_fmt(NP_ERROR, fmt_, __VA_ARGS__)

/**
 * @brief	Warning log formated
 *
 * @param	fmt_	  	Describes the format to use.
 * @param	...		  	Variable arguments providing additional information.
 */
#define NLogWarning(fmt_, ...)  \
	_np_log_fmt(NP_WARNING, fmt_, __VA_ARGS__)

/**
 * @brief	Debug log formated
 *
 * @param	fmt_		Describes the format to use.
 * @param	...			Variable arguments providing additional information.
 */
#define NLogDebug(fmt_, ...)  \
	_np_log_fmt(NP_DEBUG, fmt_, __VA_ARGS__)

/**@brief	Trace log formated.
 *
 * @param	fmt_		Describes the format to use.
 * @param	...			Variable arguments providing additional information.
 */
#define NLogTrace(fmt_, ...)  \
	_np_log_fmt(NP_TRACE, fmt_, __VA_ARGS__)
#endif


 /**@brief	Calling from no implemented functions.
 */
#define NOT_IMPLEMENTED \
	NLogError("%s: Called function with no implementation", __FUNCTION__)

/**
 * @namespace	npcore
 *
 * @brief	Core functionalities
 */
#ifdef __cplusplus
extern "C" {
#endif
	/**
	* @typedef	int NPLogLevel
	*
	* @brief	Defines an alias representing the np log level.
	* @brief	NP_FATAL NP_ERROR NP_WARNING NP_INFO NP_DEBUG NP_TRACE
	*/
	typedef int NPLogLevel;

	/**
	 * @brief	Need to call before using debug functions
	 * @return	If initialized is sucessfully 0 else -1.
	 */
	int _np_debug_initialize();

	/**
	 * @brief	Call when finished with debug functions
	 * @return	If initialized is sucessfully 0 else -1.
	 */
	int _np_debug_exit();

	/*
	* LOGGING LEVEL RUNTIME FLAGS
	*/
	static int _np_log_disabled = -1;   /**< Is all logging disabled */
	static int _np_log_out_file = 0;	/**< Is logs write to file */
	static int _np_log_out_console = 0; /**< Is logs print to console at runtime */

	/*
	* TRACING RUNTIME FLAGS
	*/
	static int _np_trace_disabled = -1; /**< Is trace disabled */
	static int _np_trace_out_file = 0;  /**< Is trace logs write to file */
	static int _np_trace_out_console = 0;/**< Is trace logs print to console at runtime  */

	/**
	 * @brief	Standard log output
	 * @param	level	The level.
	 * @param	msg  	The message.
	 */
	void _np_log(NPLogLevel level, const char* msg);

	/**
	 * @brief	Standard log output with formated input.
	 * @param	level	Log level.
	 * @param	fmt  	Describes the format to use.
	 * @param	...  	Additional arguments.
	 */
	void _np_log_fmt(NPLogLevel level, const char* fmt, ...);


	char *to_string_alloc(NPLogLevel level);

	/*
	* LOG LEVEL RUTIME FLAG
	*
	*/

	static NPLogLevel logLevel; /**< Runtime log level */


	/**@brief Full pathname of the np tracefile default file.
	 * @todo Move to "Session" struct
	*/
	static char *_np_tracefile_default_path = "log.txt";

	/** @brief Store trace logs in list for writing at end. */
	static List *_np_trace_log_text_list;

	/*********************************************************
	*
	* Determine log configuration helpers
	*/

	/**
	* @brief	Determines if we can trace logs print in console.
	*/
	int _does_trace_with_console();

	/**
	 * @brief	Determines if we can write trace logs to file.
	 */
	int _does_trace_with_file();

	/**
	 * @brief	Determines if we can log print in console.
	 */
	int _does_log_with_console();

	/**
	 * @brief	Determines if we can write logs to file.
	 */
	int _does_log_with_file();

#ifdef __cplusplus
}
#endif








#endif

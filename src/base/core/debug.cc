#if defined _MSC_VER || defined __linux__
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Windows and Linux headers
//#include <stdarg.h>
//#	include "stdio.h"
//#	include <fstream>
//#	include <stdarg.h>
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// projects headers
// 
//#include "ntime.h"
#include "debug.h"
#include "npmemory.h"
//#include "datatypes.h"
#include "npstring.h"
#include "npio.h"
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	/**
	 * @brief	Np debug initialize.
	 * 			
	 * (make trace log list,...)
	 * 
	 * @return	1 if succesfully -1 if not
	 */
	int _np_debug_initialize()
	{
		logLevel = NP_TRACE;
		if (logLevel == NP_TRACE) {
			//if trace enabled create list for logs
			_np_trace_log_text_list = list_create();
		}

		return 1;
	}

	/*
	* Exit 
	* (write trace file)
	*/

	/**
	 * @brief	Np debug exit.
	 *
	 * (write trace file)
	 * 
	 * @return	1 if succesfully -1 if not.
	 */
	int _np_debug_exit()
	{
		//write trace logs to file
		if (_does_trace_with_file()) {


		}
		list_free_default(_np_trace_log_text_list);
		
		return 1;
	}

	/**
	 * @brief	Converts a level to a string allocate.
	 *
	 * @param	level	Log level.
	 * @return	Log level as new string.
	 */
	char *to_string_alloc(NPLogLevel level) {
		char *ret = NULL;
		if (level == NP_DEBUG)
			ret = strmakeN("NP_DEBUG");
		else if (level == NP_ERROR) 
			ret = strmakeN("NP_ERROR");
		else if (level == NP_FATAL) 
			ret = strmakeN("NP_FATAL");
		else if (level == NP_INFO) 
			ret = strmakeN("NP_INFO");
		else if (level == NP_TRACE) 
			ret = strmakeN("NP_TRACE");
		else if (level == NP_WARNING) 
			ret = strmakeN("NP_WARNING");
		return ret;
	}

	/**
	 * @brief	Main log function.
	 *
	 * @param	level	Log level.
	 * @param	msg  	The message.
	 */
	void _np_log(NPLogLevel level, const char* msg)
	{
		char *levelStr = to_string_alloc(level);
		char *msgF = strmakeN("%s: %s", levelStr, msg);		

		if (_does_trace_with_console()) {
			NConsolePrint("%s", msgF);
		}			
		if (_does_trace_with_file()) {
			//Write to default trace listener	
			//	if (strncmp(_np_tracefile_default_path, _np_tracefile_default_path, strlen(_np_tracefile_default_path)) == 0) {
			//Log("tracing image. default listener");
			list_put(_np_trace_log_text_list, msgF);
			/*}
			else {
			NOT_IMPLEMENTED();
			}*/
		}

	}

	/**
	 * @brief	Formated log function
	 *
	 * @param	level	Log level.
	 * @param	fmt  	Formating.
	 * @param	...  	Arguments.
	 */
	void _np_log_fmt(NPLogLevel level, const char * fmt, ...)
	{
		char *buffer = (char*)mallocN(sizeof(char) * 512);
		/*va_list args;
		va_start(args, fmt);
		vsprintf(buffer, fmt, args);
		va_end(args);
		_np_log(level, buffer);*/
		freeN(buffer);
	}

	/**
	 * @brief	Determines if we need trace with console. Helper
	 *
	 * @return	0 if can else -1.
	 */
	int _does_trace_with_console()
	{
#ifdef _NP_LOG_DISABLED				
		return -1;
#elif  _NP_TRACE_OUT_CONSOLE		
		if (_np_trace_disabled)
			return -1;
		else if (_np_trace_out_console)
			return 0;
#endif								
		return -1;
	}

	/**
	* @brief	Determines if we need trace in file. Helper
	*
	* @return	0 if can else -1.
	*/
	int _does_trace_with_file()
	{
#ifdef _NP_LOG_DISABLED				
		return -1;
#elif  _NP_TRACE_OUT_FILE		
		if (_np_trace_disabled)
			return -1;
		else if (_np_trace_out_file)
			return 0;
#endif								
		return -1;
	}
	/**
	* @brief	Determines if we need log with file. Helper
	*
	* @return	0 if can else -1.
	*/
	int _does_log_with_file()
	{
#ifdef _NP_LOG_DISABLED				
		return -1;
#elif  _NP_LOG_OUT_FILE		
		if (_np_log_disabled)
			return -1;
		else if (_np_log_out_file)
			return 0;
#endif								
		return -1;
	}

	/**
	* @brief	Determines if we need log with console. Helper
	*
	* @return	0 if can elsevere -1.
	*/
	int _does_log_with_console()
	{
#ifdef _NP_LOG_DISABLED				
		return -1;
#elif  _NP_LOG_OUT_CONSOLE		
		if (_np_log_disabled)
			return -1;
		else if (_np_log_out_console)
			return 0;
#endif								
		return -1;
	}


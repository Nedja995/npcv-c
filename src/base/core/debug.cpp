#if defined _MSC_VER || defined __linux__
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Windows and Linux headers
// 
#	include "stdio.h"
#	include <fstream>
#	include <stdarg.h>
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#endif

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// projects headers
// 
#include "ntime.h"
#include "debug.h"
#include "datatypes.h"
#include "npio.h"
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+

namespace npcore {

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
			//output stream
			//std::ofstream traceFile;

			//fja();


			//get time
		//	NTime *lt =  time_get_allocN();
			
			//format wild time string 
		//	char *timeText = strmakeN("%02d_%02d_%02d_%02d-%02d-%02d", lt->year, lt->month, lt->day, lt->hour, lt->minute, lt->second);
	//		freeN(lt);

			//make log file path
		//	char *logFile =  strmakeN("%s.log", timeText);
			
		//	freeN(timeText);
			
			//create and open output stream
			//traceFile.open(logFile, std::ofstream::out | std::ofstream::app);
		//	freeN(logFile);
			//iterate through trace logs
		/*	LIST_FOREACH(_np_trace_log_text_list) {
				traceFile << (char*)link->data;
			}*/
		//	traceFile.close();

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
		va_list args;
		va_start(args, fmt);
		vsprintf(buffer, fmt, args);
		va_end(args);
		_np_log(level, buffer);
		freeN(buffer);
	}

	/**
	 * @brief	Determines if we need trace with console. Helper
	 *
	 * @return	true if can else false.
	 */
	bool _does_trace_with_console()
	{
#ifdef _NP_LOG_DISABLED				
		return false;
#elif  _NP_TRACE_OUT_CONSOLE		
		if (npcore::_np_trace_disabled)
			return false;
		else if (_np_trace_out_console)
			return true;
#endif								
		return false;
	}

	/**
	* @brief	Determines if we need trace in file. Helper
	*
	* @return	true if can else false.
	*/
	bool _does_trace_with_file()
	{
#ifdef _NP_LOG_DISABLED				
		return false;
#elif  _NP_TRACE_OUT_FILE		
		if (_np_trace_disabled)
			return false;
		else if (_np_trace_out_file)
			return true;
#endif								
		return false;
	}
	/**
	* @brief	Determines if we need log with file. Helper
	*
	* @return	true if can else false.
	*/
	bool _does_log_with_file()
	{
#ifdef _NP_LOG_DISABLED				
		return false;
#elif  _NP_LOG_OUT_FILE		
		if (npcore::_np_log_disabled)
			return false;
		else if (_np_log_out_file)
			return true;
#endif								
		return false;
	}

	/**
	* @brief	Determines if we need log with console. Helper
	*
	* @return	true if can elsevere false.
	*/
	bool _does_log_with_console()
	{
#ifdef _NP_LOG_DISABLED				
		return false;
#elif  _NP_LOG_OUT_CONSOLE		
		if (npcore::_np_log_disabled)
			return false;
		else if (_np_log_out_console)
			return true;
#endif								
		return false;
	}
}

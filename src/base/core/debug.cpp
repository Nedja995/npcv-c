//
//TODO: make separated file for time functions
//

//
//time_t start, end;
//double dif;
//time(&start);
//time(&end);
//dif = difftime(end, start);
//char *str = strmakeN("Your calculations took %.2lf seconds to run.\n", dif);



#if defined _MSC_VER || defined __linux__
#	include "stdio.h"
#	include <fstream>
#	include <stdarg.h>
#endif
//
//#if defined _MSC_VER
//#	include <windows.h>
//	#include <wchar.h>
//#	include <time.h>
//#endif

#include "ntime.h"

#include "debug.h"
#include "datatypes.h"
#include "npio.h"

//#include "memory.h"
//#include "npstring.h"
//#include "utils/file_ops.h"

//using namespace nputils;
using namespace npcore;

namespace npcore {

	/*
	* Initialize debug 
	* (make trace log list,...)
	*/
	int _np_debug_initialize()
	{
		logLevel = NP_TRACE;
		if (logLevel == NP_TRACE) {
			/*
			* If trace enabled create list for logs
			*/
			_np_trace_log_text_list = list_create();
		}

		return 1;
	}

	/*
	* Exit 
	* (write trace file)
	*/
	int _np_debug_exit()
	{
		//write trace logs to file
		if (_does_trace_with_file()) {
			//output stream
			std::ofstream traceFile;

			//fja();


			//get time
			NTime *lt =  time_get_allocN();
			
			//format wild time string 
			char *timeText = strmakeN("%02d_%02d_%02d_%02d-%02d-%02d", lt->year, lt->month, lt->day, lt->hour, lt->minute, lt->second);
			freeN(lt);

			//make log file path
			char *logFile =  strmakeN("%s.log", timeText);
			
			freeN(timeText);
			
			//create and open output stream
			traceFile.open(logFile, std::ofstream::out | std::ofstream::app);
			freeN(logFile);
			//iterate through trace logs
			LIST_FOREACH(_np_trace_log_text_list) {
				traceFile << (char*)link->data;
			}
			traceFile.close();

		}
		freeN(_np_trace_log_text_list);
		
		return 1;
	}

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

	/**********************************
	*
	*
	* Determine log output helpers
	*
	*
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

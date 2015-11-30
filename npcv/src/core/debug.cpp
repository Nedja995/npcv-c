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

#if defined _MSC_VER
#	include <windows.h>
	#include <wchar.h>
#endif


#include <time.h>
#include "debug.h"

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
	bool debug_initialize()
	{
		if (logLevel == NP_TRACE) {
			/*
			* If trace enabled create list for logs
			*/
			_np_trace_log_text_list = list_create();
		}

		return true;
	}

	/*
	* Exit 
	* (write trace file)
	*/
	bool debug_exit()
	{
		//write trace logs to file
		if (_does_trace_with_file()) {
			//output stream
			std::ofstream traceFile;

			//get time
			SYSTEMTIME lt;
			GetLocalTime(&lt);

			//format wild time string 
			char *timeText = (char*)mallocN(sizeof(char) * 256);
			wsprintf(timeText, "logs\\%02d_%02d_%02d_%02d-%02d-%02d", lt.wYear, lt.wMonth, lt.wDay, lt.wHour, lt.wMinute, lt.wSecond);

			//make log file path
			char *logFile = (char*)mallocN(sizeof(char) * 264);
			logFile = strmakeN("%s.log", timeText);

			//create and open output stream
			traceFile.open(logFile, std::ofstream::out | std::ofstream::app);

			//iterate through trace logs
			LIST_FOREACH(_np_trace_log_text_list) {
				traceFile << (char*)link->data;
			}
			traceFile.close();

		}
		return true;
	}

	void _np_log(NPLogLevel level, const char* msg)
	{

		if (_does_trace_with_console()) {
			NConsolePrint("%s", msg);
		}			
		if (_does_trace_with_file()) {
			//Write to default trace listener	
			//	if (strncmp(_np_tracefile_default_path, _np_tracefile_default_path, strlen(_np_tracefile_default_path)) == 0) {
			//Log("tracing image. default listener");
			list_put(_np_trace_log_text_list, msg);
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
	}

	/*
	* Determine log output helpers
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

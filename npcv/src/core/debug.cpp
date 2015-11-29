
#if defined _MSC_VER || defined __linux__
#	include "stdio.h"
#	include <fstream>
#endif
#include <stdarg.h>



#include "npio.h"
#include "debug.h"
#include "memory.h"
#include "npstring.h"
#include "utils/file_ops.h"

using namespace nputils;
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
		if (_does_trace_with_file()) {
			//write trace and logs to file
			std::ofstream traceFile;
			traceFile.open(_np_tracefile_default_path, std::ofstream::out | std::ofstream::app);

			traceFile << "Run <time> ============================================= " << std::endl;
			//iterate through trace logs
			LIST_FOREACH(_np_trace_log_text_list) {
				//write to file via stream
				traceFile << (char*)link->data;
				//free text clone
				freeN((void*)link->data);
			}
			traceFile.close();
		}
		return true;
	}

	void _np_log(NPLogLevel level, const char * msg)
	{

		if (_does_trace_with_console) {
			NConsolePrint("%s", msg);
		}			
		if (_does_trace_with_file) {
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

	void _np_log_fmt(NPLogLevel level, const char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		_np_log(level, strmakeN(fmt, args));
		va_end(args);
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
		if (npcore::_np_trace_disabled)
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

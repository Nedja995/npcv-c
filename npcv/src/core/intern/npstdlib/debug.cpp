#include "../../npstdlib/debug.h"
#include "../../npstdlib/memory.h"
#include "../../npstdlib/npstring.h"
#include "file_ops.h"

#if defined _MSC_VER || defined __linux__
#	include "stdio.h"
#	include <fstream>
#endif

using namespace nputils;

namespace npcore {



	void Log(const char *text)
	{
		Log(text, INFO);
	}

	void NTrace(const char *msg, const char * traceListener)
	{
		if (strncmp(traceListener, dbg_default_TraceFile, strlen(dbg_default_TraceFile)) == 0) {
			//Log("tracing image. default listener");
			list_put(_debug_log_text_list, strdup(msg));
		}
		else {
			NOT_IMPLEMENTED();
		}

	}

	void NTrace(const char * msg)
	{
		NTrace(msg, dbg_default_TraceFile);
	}


	bool debug_initialize()
	{
		_debug_log_text_list = list_create();
		return true;
	}

	bool debug_exit()
	{
#if defined _NP_TRACE
		//write trace and logs to file
		std::ofstream traceFile;
		traceFile.open(dbg_default_TraceFile, std::ofstream::out | std::ofstream::app);
		//iterate through trace logs
		LIST_FOREACH(_debug_log_text_list){
			//write to file via stream
			traceFile << (char*)link->data;
			//free text clone
			freeN((void*)link->data);
		}
		traceFile.close();
#endif
		return true;
	}

	void Log(const char *text, LogLevel level)
	{
		if (level > logLevel) {
			return;
		}

		#if defined _MSC_VER || defined __linux__
			//printf(text);
			//printf("\n");
		#endif

			if (DebugLogWrite) {
				NTrace(strdup(text));
			}


	}


}

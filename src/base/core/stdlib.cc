#include "npstdlib.h"


int NPCORE_initialize()
{
	return _np_debug_initialize();
}

int NPCORE_exit()
{
	return _np_debug_exit();
}

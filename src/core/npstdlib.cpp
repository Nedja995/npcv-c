#include "npstdlib.h"


namespace npcore {



	int NPCORE_initialize()
	{
		return _np_debug_initialize();
	}

	int NPCORE_exit()
	{
		return _np_debug_exit();
	}

}
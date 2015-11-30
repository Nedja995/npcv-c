#include "path_utils.h"
#include "core/npstring.h"

using namespace npcore;

namespace nputils {

	void path_to_linux(char * winPath)
	{
		
		strreplaceN(winPath, "\\", "\/");
	}
	void path_to_windows(char * unixPath)
	{
		strreplaceN(unixPath, "\/", "\\");
	}
	char *path_to_linux_alloc(char * winPath)
	{
		char *ret = strdup(winPath);
		strreplaceN(ret, "\\", "\/");
		return ret;
	}
	char *path_to_windows_alloc(char * unixPath)
	{
		char *ret = strdup(unixPath);
		strreplaceN(ret, "\/", "\\");
		return ret;
	}
}

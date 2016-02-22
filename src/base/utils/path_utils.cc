#include "path_utils.h"
#include "base\core\npstdlib.h"


void path_to_linux(char * winPath)
{
		
	strreplaceN(winPath, "\\\\", "\/");
}
void path_to_windows(char * unixPath)
{
	strreplaceN(unixPath, "\/", "\\");
}
char *path_to_linux_alloc(char * winPath)
{
	char *ret = (char*)duplicateN(winPath, sizeof(char) * strnlenN(winPath));
	strreplaceN(ret, "\\", "\/");
	return ret;
}
char *path_to_windows_alloc(char * unixPath)
{
	char *ret = (char*)duplicateN(unixPath, sizeof(char) * strnlenN(unixPath));
	strreplaceN(ret, "\/", "\\");
	return ret;
}
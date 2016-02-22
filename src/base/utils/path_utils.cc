/*
* Copyright (c) 2016 Nedeljko Pejasinovic (nedjaunity@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


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
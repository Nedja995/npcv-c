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


/**
*  \brief Utilities for path
*
*  \file path_utils.h
*
*  \ingroup utils
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NP_PATH_UTILS_H__
#define __NP_PATH_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * @brief	Path to linux.

	 * @param [in,out]	winPath	If non-null, full pathname of the window file.
	 */
	void path_to_linux(char *winPath);

	/**
	 * @brief	Path to windows.
	 *
	 * @param [in,out]	unixPath	If non-null, full pathname of the unix file.
	 */
	void path_to_windows(char *unixPath);

	/**
	 * @brief	Path to linux allocate.
	 *
	 * @param	winPath	Full pathname of the window file.
	 * @return	null if it fails, else a char*.
	 */
	char *path_to_linux_alloc(const char *winPath);

	/**
	 * @brief	Path to windows allocate.
	 *
	 * @param	unixPath	Full pathname of the unix file.
	 * @return	null if it fails, else a char*.
	 */
	char *path_to_windows_alloc(const char *unixPath);

#ifdef __cplusplus
}
#endif
#endif
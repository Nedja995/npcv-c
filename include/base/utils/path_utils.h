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
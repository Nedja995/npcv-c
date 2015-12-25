/**
*  \brief File utilities
*
*  \file file_ops.h
*
*  \ingroup utils
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NPCV_FILE_OPS_H__
#define __NPCV_FILE_OPS_H__

/**
 * @namespace	nputils
 *
 * @brief	Utilities and helpers for npcv
 */
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * @brief	File write.
	 *
	 * @param	filepath	The filepath.
	 * @param	text		Text to write.
	 * @return	true if it succeeds, false if it fails.
	 */
	int file_write(const char * filepath, const char * text);
#ifdef __cplusplus
}
#endif
#endif
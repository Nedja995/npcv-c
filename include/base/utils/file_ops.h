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
namespace nputils
{
	/**
	 * @brief	File write.
	 *
	 * @param	filepath	The filepath.
	 * @param	text		Text to write.
	 * @return	true if it succeeds, false if it fails.
	 */
	bool file_write(const char * filepath, const char * text);
}

#endif
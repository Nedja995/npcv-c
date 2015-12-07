/**
*  \brief Gray processing functions
*
*  \file imageproc_gray.h
*
*  \ingroup imageproc
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NPCV__GRAY_H__
#define __NPCV_GRAY_H__

#include "base/core/Image.h"

using namespace npcore;

namespace npip{

	/**
	 * @brief	Grays the given image.
	 *
	 * @param [in,out]	image	Image.
	 * @return	true if it succeeds, false if it fails.
	 */
	bool gray(Image * image);

}

#endif
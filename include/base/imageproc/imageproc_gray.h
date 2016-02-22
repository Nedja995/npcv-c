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

#include "base/imageproc/image.h"


//namespace npip{
#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * @brief	Grays the given image.
	 *
	 * @param [in,out]	image	Image.
	 * @return	true if it succeeds, false if it fails.
	 */
	int np_gray_simple(Image *image);

	/**
	 * @brief	Np gray matrix.
	 *
	 * @param [in,out]	image	If non-null, the image.
	 *
	 * @return	An int.
	 */
	int np_gray_matrix(Image *image);

#ifdef __cplusplus
}
#endif
#endif
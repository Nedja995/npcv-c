/**
*  \brief Edge detection functions
*
*  \file edge_detection.h
*
*  \ingroup imageproc
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NPCV_EDGE_DETECTION_H__
#define __NPCV_EDGE_DETECTION_H__

#include "base/core/Image.h"

using namespace npcore;

/**
 * @namespace	npip
 *
 * @brief	Image processing namespace
 */
namespace npip {

	/**
	 * @brief Set specific color for edge and not edge pixel.
	 *
	 * @param [in,out]	image	If non-null, the image.
	 * @param	resolution   	The resolution.
	 * @param	sensitivity  	The sensitivity.
	 */
	void contour_draw_custom(Image * image, int resolution, int sensitivity);
}


#endif



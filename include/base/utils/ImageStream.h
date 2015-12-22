/**
*  \brief Image streams
*
*   There is integrated thirdpart STB lib for image loading
*   https://github.com/nothings/stb/stb_image.h
*
*  \file ImageStream.h
*
*  \ingroup utils
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NSD_IMAGE_READER__
#define __NSD_IMAGE_READER__

#include "base/imageproc/image.h"


#ifdef __cplusplus
extern "C" {
#endif

	/**
	* @brief	Reads image with STB image
	*
	* @param	filepath	The filepath.
	* @return	null if it fails, else the loaded image.
	*/
	static Image * ReadImage_STB(const char * filepath);

	/**
	* @brief	Writes an image with STB image.
	*
	* @param	image   	The image.
	* @param	filepath	The filepath.
	*
	* @return	true if it succeeds, false if it fails.
	*/
	static bool WriteImage_STB(const Image * image, const char * filepath);

#ifdef __cplusplus
}
#endif


#endif
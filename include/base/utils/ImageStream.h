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

#include "base/core/Image.h"

using namespace npcore;

namespace nputils
{
	/**
	 * @class	ImageStream
	 *
	 * @brief	Reading and writing image via streams
	 */
	class ImageStream
	{
	public:
		/**
		 * @brief	Reads image with STB image
		 *
		 * @param	filepath	The filepath.
		 * @return	null if it fails, else the loaded image.
		 */
		static npcore::Image * ReadImage_STB(const char * filepath);

		/**
		 * @brief	Writes an image with STB image.
		 *
		 * @param	image   	The image.
		 * @param	filepath	The filepath.
		 *
		 * @return	true if it succeeds, false if it fails.
		 */
		static bool WriteImage_STB(const Image * image, const char * filepath);
	};
}


#endif
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
*  \brief Image streams
*
*   There is integrated thirdpart STB lib for image loading
*   https://github.com/nothings/stb/stb_image.h
*
*  \file ImageStream.h
*
*  \ingroup imageproc
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NSD_IMAGE_READER__
#define __NSD_IMAGE_READER__

#include "image.h"


#ifdef __cplusplus
extern "C" {
#endif

	/**
	* @brief	Reads image with STB image
	*
	* @param	filepath	The filepath.
	* @return	null if it fails, else the loaded image.
	*/
	Image * ReadImage_STB(const char * filepath);

	/**
	* @brief	Writes an image with STB image.
	*
	* @param	image   	The image.
	* @param	filepath	The filepath.
	*
	* @return	true if it succeeds, false if it fails.
	*/
	bool WriteImage_STB(const Image * image, const char * filepath);

#ifdef __cplusplus
}
#endif


#endif
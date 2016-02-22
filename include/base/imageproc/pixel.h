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

#ifndef __NPCV_PIXEL_H__
#define __NPCV_PIXEL_H__

/** 
*  \brief Pixel base struct
*
*  One of project base struct 
*   which represent pixel
*  
*  \file pixel.h
*
*  \ingroup core
*
*  \author Nedeljko Pejasinovic
*
*/

#define PIXEL_MAX_STRING 500 // pixel_string_alloc() LIMIT

#include "base\core\npstdlib.h"

#ifdef __cplusplus
extern "C" {
#endif
	/**
	 * @struct	Pixel
	 * @brief	A pixel.
	 */
	typedef struct Pixel 
	{
		int r, g, b;
		uchar *ptr;
	} Pixel;

	/**
	 * @brief	Contructor for Pixel.
	 *
	 * @param [in,out]	pixel	If non-null, the pixel.
	 * @return	null if it fails, else new Pixel with passed pointer and values.
	 */
	Pixel * pixel_create(uchar * pixel);

	/**
	 * @brief	String representation for Pixel structure
	 *
	 * @param	pixel	The pixel.
	 * @return	null if it fails, else a char*.
	 */
	char *pixel_string_alloc(const Pixel *pixel);





/*
* HELPERS
*/

/*
 Foreach
 use example:
 comb1:
		IMAGE_FOREACH(image)	//
				pixel->r;
				pixel->g;
				...				// USE PIXEL
		END_FOREACH				//

 comb2:
		IMAGE_FOREACH(image)	//
				pixel->r;
				pixel->g;
				...				// USE PIXEL
			END_ITER_Y			//
			// x++
		END_FOREACH2			//

 comb2:
		IMAGE_FOREACH(image)	//
				pixel->r;
				pixel->g;
				...				// USE PIXEL
			END_FOREACH2		// WITHOUT FREEING Pixel object
			// x++
		END_FOREACH2			*/

/**
 * @brief	Helpers for iterate throught image pixels.
 *
 * @param	image	The image.
 */
#define IMAGE_FOREACH(image)							\
	Pixel *pixel = NULL;								\
	for (int x = 0; x < image->width; x++) {				\
		for (int y = 0; y < image->height; y++) {			\
			pixel = image_get_pixel(image, x, y);	

// End foreach
#define END_FOREACH freeN(pixel); } }

// End foreach 2
#define END_ITER_Y  freeN(pixel);}
#define END_FOREACH2 }

#ifdef __cplusplus
}
#endif


#endif
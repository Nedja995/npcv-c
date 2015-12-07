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

#include "datatypes.h"

namespace npcore 
{
	/**
	 * @struct	Pixel
	 * @brief	A pixel.
	 */
	struct Pixel 
	{
		int r, g, b;
		uchar *ptr;
	};

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

	/**
	 * @brief	Pixel trace.
	 *
	 * @param	pixel		 	The pixel.
	 * @param	traceListener	The trace listener.
	 */
	void pixel_trace(const Pixel *pixel, const char *traceListener);

	void pixel_trace(const Pixel *pixel);



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
	for (int x = 0; x < img->width; ++x) {				\
		for (int y = 0; y < img->height; ++y) {			\
			pixel = image_get_pixel(img, x, y);	

// End foreach
#define END_FOREACH freeN(pixel); } }

// End foreach 2
#define END_ITER_Y  freeN(pixel);}
#define END_FOREACH2 }

}


#endif
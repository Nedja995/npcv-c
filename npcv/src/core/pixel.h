#ifndef __NPCV_PIXEL_H__
#define __NPCV_PIXEL_H__

#define PIXEL_MAX_STRING 500 // pixel_string_alloc() LIMIT

#include "npstdlib/datatypes.h"

namespace npcore 
{


	struct Pixel 
	{
		int r, g, b;
		uchar *ptr;
	};

	Pixel * pixel_create(uchar * pixel);

	char *pixel_string_alloc(const Pixel *pixel);

	//trace
	void pixel_trace(const Pixel *pixel, const char *traceListener);
	void pixel_trace(const Pixel *pixel);


/*************************************************
* 
* MACROS
*/

/*
* DEBUG
*/

// Trace
#if defined _NP_TRACE
#	define TRACE_PIXEL(pixel)						\
		char *msg = "trace:Pixel: ";				\
		char *str = pixel_string_alloc(pixel);		\
		strcat(msg, str);							\
		Log(msg);
#else
#	define TRACE_PIXE()
#endif


/*
* HELPERS
*/

// Foreach
// use example:
// comb1:
//		IMAGE_FOREACH(image)	//
//				pixel->r;
//				pixel->g;
//				...				// USE PIXEL
//		END_FOREACH				//
//
// comb2:
//		IMAGE_FOREACH(image)	//
//				pixel->r;
//				pixel->g;
//				...				// USE PIXEL
//			END_ITER_Y			//
//			// x++
//		END_FOREACH2			//
//
// comb2:
//		IMAGE_FOREACH(image)	//
//				pixel->r;
//				pixel->g;
//				...				// USE PIXEL
//			END_FOREACH2		// WITHOUT FREEING Pixel object
//			// x++
//		END_FOREACH2			//
#define IMAGE_FOREACH(image)							\
	Pixel *pixel = NULL;								\
	for (int x = 0; x < img->width; ++x) {				\
		for (int y = 0; y < img->height; ++y) {			\
			pixel = image_get_pixel(img, x, y);	

// End foreach
#define END_FOREACH freeN(pixel); } }

#define END_ITER_Y  freeN(pixel);}
#define END_FOREACH2 }

}


#endif
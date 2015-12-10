#ifndef __NSDK_IMAGE_H__
#define __NSDK_IMAGE_H__
/**
*  @brief Base image structure
*
*	Low level image representation 
*	and functions
*
*  @file Image.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*
*  @todo Write functions image_each_pixel( img, (void)(cb_pixel_process*)(pixel*) )
*	  which will iterate and process each pixel
*	  throught passed callback
*/

#include "pixel.h"
#include "datatypes.h"

/**
 * @brief	Return pointer to R component in pixel.
 * @param	Pixel struct.
 */
#define R(pixel) *pixel->ptr
 /**
 * @brief	Return pointer to G component in pixel.
 * @param	Pixel struct.
 */
#define G(pixel) *(pixel->ptr + 1)
 /**
 * @brief	Return pointer to B component in pixel.
 * @param	Pixel struct.
 */
#define B(pixel) *(pixel->ptr + 2)

namespace npcore
{
	/**
	 * @struct	Image
	 *
	 * @brief	Image presentation.
	 */
	struct Image
	{
		uchar *data; /**< Array of pixels */
		int width;
		int height;
		int type; /**< Pixel components number */
	};

	/**
	 * @brief	Contstructor for image.
	 * 			
	 * @param   data			Array of pixels.
	 * @param	width			width.
	 * @param	height			height.
	 * @param	components  	Pixel components number.
	 * @return	null if it fails, else pointer to new image.
	 */
	Image * image_create(const uchar * data, int width, int height, int components);

	/**  
     * @brief	Get Pixel from image.
	 * 			
	 * @param	image	The Image.
	 * @param	x	 	The x coordinate.
	 * @param	y	 	The y coordinate.
	 * @return	null if it fails,or a pointer to pixel at image.
	 */
	Pixel * image_get_pixel(const Image * image, int x, int y);

	/**
	 * @brief	Get subimage
	 * 			
	 * @param	image 	The image.
	 * @param	x	  	The x coordinate.
	 * @param	y	  	The y coordinate.
	 * @param	width 	The width.
	 * @param	height	The height.
	 * @return	null if it fails, else an pointer to new allocated image.
	 */
	Image * image_get_area(const Image * image, int x, int y, int width, int height);

	/**
	 * @brief	Image data get size.
	 * 			
	 * @param	width 	The width.
	 * @param	height	The height.
	 * @param	type  	The type.
	 * @return	Sum of components and all pixels.
	 */
	size_t image_data_get_size(const int width, const int height, const int type);

	/**
	 * @brief	String representation of Image struct

	 * @param	image	The image. pointer to new string.
	 */
	char *image_string_alloc(const Image *image);

	
	void free_image(Image *image);
	


	/**
	 * @brief	Image trace.
	 *
	 * @param	image	The image.
	 */
	//void image_trace(const Image *image);

	/**
	 * @brief	Image trace.
	 *
	 * @param	image		 	The image.
	 * @param	traceListener	The trace listener.
	 */
//	void image_trace(const Image *image, const char *traceListener);
}


#endif

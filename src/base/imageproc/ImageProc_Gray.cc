#include "imageproc_gray.h"
#include "base/core/npstdlib.h"

int np_gray_simple(Image * image)
{
	for (int x = 0; x < image->width; ++x)
	{
		for (int y = 0; y < image->height; ++y)
		{
			Pixel* px = image_get_pixel(image, x, y);
			R(px) /= 2;
			G(px) /= 2;
			B(px) /= 2;
			freeN(px);
		}
	}
	return 0;
}

int np_gray_matrix(Image * image)
{
	/* Filter matrix */
	const int filterWidth = 5;
	const int filterHeight = 5;	
	float filter[filterWidth][filterHeight] =
	{
		0,  0, -1,  0,  0,
		0,  0, -1,  0,  0,
		0,  0,  4,  0,  0,
		0,  0, -1,  0,  0,
		0,  0, -1,  0,  0,
	};

	/* Multiply result with factor */
	float factor = 1.0 ;
	/* Make image brightnes */
	float bias = 0.0;

	//temporals
	Pixel *pixel = NULL; //curent center pixel
	Pixel *pixelProc = NULL; //curent pixel that is processing with filter
	for (int x = 0; x < image->width; x++) {
	for (int y = 0; y < image->height; y++)
	{	
		
		float red = 0.0f, green = 0.0f, blue = 0.0f;
		//iterate throught matrix
		for (int mx = 0; mx < filterWidth; mx++) {
			for (int my = 0; my < filterHeight; my++)
			{
				int imageX = (x - filterWidth / 2 + mx + image->width) % image->width;
				int imageY = (y - filterHeight / 2 + my + image->height) % image->height;
				pixelProc = image_get_pixel(image, imageX, imageY);
				red += R(pixelProc) * filter[mx][my];
				green += G(pixelProc) * filter[mx][my];
				blue += B(pixelProc) * filter[mx][my];
				freeN(pixelProc);
			}
		}
		pixel = image_get_pixel(image, x, y);
		R(pixel) = np_min(np_max(int(factor * red + bias), 0), 255);
		G(pixel) = np_min(np_max(int(factor * green + bias), 0), 255);
		B(pixel) = np_min(np_max(int(factor * blue + bias), 0), 255);
		freeN(pixel);
	}}

	return 0;
}

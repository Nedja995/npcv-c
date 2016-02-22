#include "base/imageproc/convolution_matrix.h"
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

Image * apply_matrix_alloc(Image * image)
{
	Image * ret = image_create_blank(image->width, image->height, image->type);

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
	float factor = 1.0;
	/* Make image brightnes */
	float bias = 0.0;

	//temporals
	Pixel *pixel = NULL; //curent center pixel
	Pixel *pixelProc = NULL; //curent pixel that is processing with filter
	for (int x = 0; x < image->width; x++) {
	for (int y = 0; y < image->height; y++) {
			float red = 0.0f, green = 0.0f, blue = 0.0f;
			//iterate throught matrix
			for (int mx = 0; mx < filterWidth; mx++) {
			for (int my = 0; my < filterHeight; my++){
					int imageX = (x - filterWidth / 2 + mx + image->width) % image->width;
					int imageY = (y - filterHeight / 2 + my + image->height) % image->height;
					pixelProc = image_get_pixel(image, imageX, imageY);
					red += R(pixelProc) * filter[mx][my];
					green += G(pixelProc) * filter[mx][my];
					blue += B(pixelProc) * filter[mx][my];
					freeN(pixelProc);
				}
			}
			pixel = image_get_pixel(ret, x, y);
			R(pixel) = np_min(np_max(int(factor * red + bias), 0), 255);
			G(pixel) = np_min(np_max(int(factor * green + bias), 0), 255);
			B(pixel) = np_min(np_max(int(factor * blue + bias), 0), 255);
			freeN(pixel);
		}
	}

	return ret;
}

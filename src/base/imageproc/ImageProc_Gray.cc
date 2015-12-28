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
	const int filterWidth = 9;
	const int filterHeight = 9;	
	double filter[filterWidth][filterHeight] =
	{
		1, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 1,
	};

	/* Multiply result with factor */
	double factor = 1.0 / 9.0;
	/* Make image brightnes */
	double bias = 0.0;

	//temporal

	IMAGE_FOREACH(image)
		double red = 0.0f, green = 0.0f, blue = 0.0f;
		//iterate throught matrix
		for (int mx = 0; mx < filterWidth; mx++) {
			for (int my = 0; my < filterHeight; my++)
			{
				int imageX = (x - filterWidth / 2 + mx + image->width) % image->width;
				int imageY = (y - filterHeight / 2 + my + image->height) % image->height;

				red +=  R(pixel) * filter[mx][my];
				green += G(pixel) * filter[mx][my];
				blue += B(pixel) * filter[mx][my];
			}
		}
		int rp = int(factor * red + bias);
		rp = np_max(rp, 0);
		rp = np_min(rp, 255);
		R(pixel) = np_min(np_max(int(factor * red + bias), 0), 255);
		G(pixel) = np_min(np_max(int(factor * green + bias), 0), 255);
		B(pixel) = np_min(np_max(int(factor * blue + bias), 0), 255);
	END_FOREACH

	return 0;
}

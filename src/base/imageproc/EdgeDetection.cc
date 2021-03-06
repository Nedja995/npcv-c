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

#include "base/core/npstdlib.h"
#include "edge_detection.h"


	void contour_draw_custom(Image * image, int resolution, int sensitivity)
	{
		// X
		for (int x = 0; x < image->width; ++x)
		{
			for (int y = 0; y < image->height; ++y)
			{
				if (x < resolution + 1 || x + resolution + 1 > image->width)
				{
					continue;
				}
				Pixel * center = image_get_pixel(image, x, y);

				Pixel *left = image_get_pixel(image, x - resolution, y);
				Pixel *right = image_get_pixel(image, x + resolution, y);

				int centerGray = (center->r + center->g + center->b) / 3;
				int leftGray = (left->r + left->g + left->b) / 3;
				int rightGray = (right->r + right->g + right->b) / 3;


				freeN(left);
				freeN(right);

				if (/*abs(*/centerGray - leftGray/*)*/ < sensitivity
					|| /*abs(*/centerGray - rightGray/*)*/ < sensitivity)
				{
					*center->ptr++ = 0; // b
					*center->ptr++ = 0; // g
					*center->ptr++ = 0; //r
				}
				else
				{
					//edge
					*center->ptr++ = 255; // b
					*center->ptr++ = 255; // g
					*center->ptr++ = 255; // r
				}

				freeN(center);

			}
		}

		//x reverse
		//for (int x = image->width; x >0; --x)
		//{
		//	for (int y = image->height; y  > 0;--y)
		//	{
		//		if (x < resolution + 1 || x + resolution + 1 > image->width)
		//		{
		//			continue;
		//		}
		//		Pixel * center = image_get_pixel(image, x, y);

		//		Pixel *left = image_get_pixel(image, x - resolution, y);
		//		Pixel *right = image_get_pixel(image, x + resolution, y);

		//		int centerGray = (center->r + center->g + center->b) / 3;
		//		int leftGray = (left->r + left->g + left->b) / 3;
		//		int rightGray = (right->r + right->g + right->b) / 3;


		//		freeN(left);
		//		freeN(right);

		//		if (abs(centerGray - leftGray) < sensitivity
		//			|| abs(centerGray - rightGray) < sensitivity)
		//		{
		//			*center->ptr++ = 0; // b
		//			*center->ptr++ = 0; // g
		//			*center->ptr++ = 0; //r
		//		}
		//		else
		//		{
		//			//edge
		//			*center->ptr++ = 255; // b
		//			*center->ptr++ = 255; // g
		//			*center->ptr++ = 255; // r
		//		}

		//		freeN(center);

		//	}
		//}

		// Y
		//for (int x = 0; x < image->width; ++x)
		//{
		//	for (int y = 0; y < image->height; ++y)
		//	{
		//		if (y < resolution + 1 || y + resolution + 1 > image->height)
		//		{
		//			continue;
		//		}
		//		Pixel * center = image_get_pixel(image, x, y);

		//		Pixel *up = image_get_pixel(image, x , y - resolution);
		//		Pixel *down = image_get_pixel(image, x , y + resolution);

		//		int centerGray = (center->r + center->g + center->b) / 3;
		//		int leftGray = (up->r + up->g + up->b) / 3;
		//		int rightGray = (down->r + down->g + down->b) / 3;


		//		freeN(up);
		//		freeN(down);

		//		if (abs(centerGray - leftGray) < sensitivity
		//			|| abs(centerGray - rightGray) < sensitivity)
		//		{
		//			*center->ptr++ = 0; // b
		//			*center->ptr++ = 0; // g
		//			*center->ptr++ = 0; //r
		//		}
		//		else
		//		{
		//			//edge
		//			*center->ptr++ = 255; // b
		//			*center->ptr++ = 255; // g
		//			*center->ptr++ = 255; // r
		//		}

		//		freeN(center);

		//	}
		//}

		//y reverse
		//for (int x = image->width; x > 0; --x)
		//{
		//	for (int y = image->height; y > 0; --y)
		//	{
		//		if (y < resolution + 1 || y + resolution + 1 > image->height)
		//		{
		//			continue;
		//		}
		//		Pixel * center = image_get_pixel(image, x, y);

		//		Pixel *up = image_get_pixel(image, x, y - resolution);
		//		Pixel *down = image_get_pixel(image, x, y + resolution);

		//		int centerGray = (center->r + center->g + center->b) / 3;
		//		int leftGray = (up->r + up->g + up->b) / 3;
		//		int rightGray = (down->r + down->g + down->b) / 3;


		//		freeN(up);
		//		freeN(down);

		//		if (abs(centerGray - leftGray) < sensitivity
		//			|| abs(centerGray - rightGray) < sensitivity)
		//		{
		//			*center->ptr++ = 0; // b
		//			*center->ptr++ = 0; // g
		//			*center->ptr++ = 0; //r
		//		}
		//		else
		//		{
		//			//edge
		//			*center->ptr++ = 255; // b
		//			*center->ptr++ = 255; // g
		//			*center->ptr++ = 255; // r
		//		}

		//		freeN(center);

		//	}
		//}




	}


//int main() { return 0; }
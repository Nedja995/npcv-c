#include "../edge_detection.h"

namespace npip {

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

				if (abs(centerGray - leftGray) < sensitivity
					|| abs(centerGray - rightGray) < sensitivity)
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
		for (int x = 0; x < image->width; ++x)
		{
			for (int y = 0; y < image->height; ++y)
			{
				if (y < resolution + 1 || y + resolution + 1 > image->height)
				{
					continue;
				}
				Pixel * center = image_get_pixel(image, x, y);

				Pixel *up = image_get_pixel(image, x , y - resolution);
				Pixel *down = image_get_pixel(image, x , y + resolution);

				int centerGray = (center->r + center->g + center->b) / 3;
				int leftGray = (up->r + up->g + up->b) / 3;
				int rightGray = (down->r + down->g + down->b) / 3;


				freeN(up);
				freeN(down);

				if (abs(centerGray - leftGray) < sensitivity
					|| abs(centerGray - rightGray) < sensitivity)
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
}
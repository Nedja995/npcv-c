#include "../Image.h"


namespace npcore
{
	Image* image_create(uchar* data, int width, int height, int type)
	{
		Image* ret = mallocN<Image>();

		size_t memSize = sizeof(uchar) * width * height * 3;
		ret->data = (uchar*)duplicateN((void*)data, memSize);
		ret->height = height;
		ret->width = width;
		ret->type = type;

		return ret;
	}

	Pixel * image_get_pixel(const Image * image, int x, int y)
	{
		uchar * pixel = 0;
		int columnPosition = x * image->type;
		int rowBeginPosition = image->width * image->type * y;
		uchar* rowBegin = image->data + rowBeginPosition;
		pixel = rowBegin + columnPosition;
		return pixel_create(pixel);

	}

	int image_get_pixel_mem_position(const Image * image, int x, int y)
	{
		int pos = 0;
		int columnPosition = x * image->type;
		int rowBeginPosition = image->width * image->type * y;
		pos = rowBeginPosition + columnPosition;
		return pos;
	}


	size_t image_data_get_size(const int width, const int height, const int type)
	{
		return width * height * type;
	}

	Image * image_get_area(const Image * image, int x, int y, int width, int height)
	{
		Image * ret = 0;
		Pixel * pixelTemp = 0;
		uchar * newData = 0;

		int srcPos, srcColumnPosition, srcCowBeginPosition, srcOffset;
		int dstPos, dstColumnPosition, dstCowBeginPosition, dstOffset;

		uchar *ipx;

		if (x + width > image->width || y + height > image->height)
		{
			//bad params...
		}
		else
		{
			newData = (uchar *)mallocN(image_data_get_size(width, height, image->type) * sizeof(uchar));

			srcColumnPosition = x * image->type;
			srcCowBeginPosition = image->width * image->type * y;
			srcPos = srcCowBeginPosition + srcColumnPosition;
			srcOffset = srcPos;

			dstColumnPosition = 0;
			dstCowBeginPosition = width * image->type * y;
			dstPos = dstCowBeginPosition + dstColumnPosition;
			dstOffset = dstPos;
			ipx = 0;

			for (int ix = x; ix < width + x; ix++)
			{
				for (int iy = y; iy < height + y; iy++)
				{
					srcColumnPosition = ix * image->type;
					srcCowBeginPosition = image->width * image->type * iy;
					srcOffset = srcCowBeginPosition + srcColumnPosition;

					ipx = image->data + srcOffset;

					dstColumnPosition = (ix - x) * image->type;
					dstCowBeginPosition = width * image->type * iy;
					dstPos = dstCowBeginPosition + dstColumnPosition;

					memcpyN(newData + dstPos - dstOffset, ipx, sizeof(uchar) * image->type);
				}
			}
			ret = image_create(newData, width , height, image->type);
		}
		return ret;
	}
}


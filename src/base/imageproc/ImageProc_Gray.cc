#include "imageproc_gray.h"
#include "base/core/npstdlib.h"

//namespace npip{

	int n_gray(Image * image)
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
//}

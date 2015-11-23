#include "../pixel.h"

namespace npcore 
{
	Pixel * pixel_create(uchar * pixel)
	{
		Pixel * ret = (Pixel *)mallocN(sizeof(Pixel));

		ret->r = (int)*pixel;
		ret->g = (int)*(pixel + 1);
		ret->b = (int)*(pixel + 2);

		ret->ptr = pixel;

		return ret;
	}


}

 
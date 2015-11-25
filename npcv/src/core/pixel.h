#ifndef __NPCV_PIXEL_H__
#define __NPCV_PIXEL_H__

#include "npstdlib/npstdlib.h"

namespace npcore 
{

	struct Pixel 
	{
		int r, g, b;
		uchar *ptr;
	};

	Pixel * pixel_create(uchar * pixel);
}


#endif
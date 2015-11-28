#include "../pixel.h"
#include "../npstdlib/npstring.h"
#include "../npstdlib/debug.h"

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

	char *pixel_string_alloc(const Pixel * pixel)
	{
		char *ret = string_alloc(PIXEL_MAX_STRING);
		ret[0] = '\0';
		char strR[15], strG[15], strB[15];
		sprintf(strR, "%i:", pixel->r);
		sprintf(strG, "%i:", pixel->g);
		sprintf(strB, "%i ", pixel->b);
		strcat(ret, strR);
		strcat(ret, strG);
		strcat(ret, strB);
		return ret;
	}

	//trace
	void pixel_trace(const Pixel * pixel, const char *listener)
	{
		if (strncmp(listener, dbg_default_TraceFile, strlen(dbg_default_TraceFile)) == 0) {
			Log("tracing image. default listener");
		}
		else {
			NOT_IMPLEMENTED();
		}
	}
	//trace default
	void pixel_trace(const Pixel * pixel)
	{
		pixel_trace(pixel, dbg_default_TraceFile);
	}


}

 
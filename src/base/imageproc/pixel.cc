#include "pixel.h"
#include "base\core\npstdlib.h"

	Pixel *pixel_create(uchar *pixel)
	{
		Pixel *ret = (Pixel *)mallocN(sizeof(Pixel));

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
		sprintfN(strR, "%i:", pixel->r);
		sprintfN(strG, "%i:", pixel->g);
		sprintfN(strB, "%i ", pixel->b);
		sprintfN(ret, strR);
		strappendN(ret, strG);
		strappendN(ret, strB);
		return ret;
	}

	//trace
	void pixel_trace(const Pixel * pixel, const char *listener)
	{
		if (/*strncmp(listener, _np_tracefile_default_path, strlen(_np_tracefile_default_path)) == 0*/false) {
			//Log("tracing image. default listener");
		}
		else {
			NOT_IMPLEMENTED;
		}
	}
	//trace default
	void pixel_trace(const Pixel * pixel)
	{
		//pixel_trace(pixel, _np_tracefile_default_path);
	}

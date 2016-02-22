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

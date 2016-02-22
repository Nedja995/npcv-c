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

//#include <string>

#include "base\core\npstdlib.h"
#include "npimage_utils.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif
#include "stb_image.h"
#include "stb_image_write.h"

Image * ReadImage_STB(const char *filepath)
{
	int width, height, type;
	Image * ret = 0;
	uchar * data = stbi_load(filepath, &width, &height, &type, 3);
	if (data == NULL) {
		char *pat = strdup(filepath);
		//NLogError("\nCannot load image from: %s", pat);
		return NULL;
	}

	ret = image_create(data, width, height, type);

	//free_image(ret);
	freeN(data);

	return ret;
}

bool WriteImage_STB(const Image * image, const char * filepath)
{
	int res = stbi_write_png(filepath, image->width, image->height, image->type, image->data, 0);

	return true;
}
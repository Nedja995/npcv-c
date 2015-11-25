#include "../../core/Image.h"
#include "../ImageStream.h"
#include "../core/npstdlib/string.h"
#include "../core/npstdlib/debug.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif
#include "../../../lib/stb/stb_image.h"
#include "../../../lib/stb/stb_image_write.h"

using namespace npcore;

namespace nputils
{
	Image * ImageStream::ReadImage_STB(const char *filepath)
	{
		int width, height, type;
		char strW[15], strH[15], strT[15];
		Image * ret = 0;
		uchar * data = stbi_load(filepath, &width, &height, &type, 3);

		sprintfN(strW, "%ix", width); sprintfN(strH, "%i ", height); 
		Log(" image loaded ", DEBUG); Log(strW, DEBUG); Log(strH, DEBUG);

		ret = image_create(data, width, height, type);
		Log(" image created ", DEBUG); //Log(width, DEBUG); Log("", width);

		return ret;
	}

	bool ImageStream::WriteImage_STB(const Image * image, const char * filepath)
	{
		int res = stbi_write_png(filepath, image->width, image->height, image->type, image->data, 0);

		return true;
	}

}

//int main() { return 0;  }

//#include <string>

#include "base/core/Image.h"
#include "ImageStream.h"
#include "base/core/npstring.h"
#include "base/core/debug.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif
#include "stb_image.h"
#include "stb_image_write.h"

using namespace npcore;

namespace nputils
{
	Image * ImageStream::ReadImage_STB(const char *filepath)
	{
		int width, height, type;
		Image * ret = 0;
		uchar * data = stbi_load(filepath, &width, &height, &type, 3);
		if (data == NULL) {
			char *pat = strdup(filepath);
			NLogError("\nCannot load image from: %s", pat);
			return NULL;
		}

		ret = image_create(data, width, height, type);
		return ret;
	}

	bool ImageStream::WriteImage_STB(const Image * image, const char * filepath)
	{
		int res = stbi_write_png(filepath, image->width, image->height, image->type, image->data, 0);

		return true;
	}

}

//int main() { return 0;  }

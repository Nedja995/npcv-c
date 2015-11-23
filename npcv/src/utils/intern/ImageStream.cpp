#include "../../core/Image.h"
#include "../ImageStream.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#endif

#include "../stb_image.h"
#include "../stb_image_write.h"


namespace nputils
{
	Image * ImageStream::ReadImage_STB(const char *filepath)
	{
		int width;
		int height;
		int type;
		Image * ret = 0;
		uchar * data = stbi_load(filepath, &width, &height, &type, 3);

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
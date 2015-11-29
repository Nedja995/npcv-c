#include <string>

#include "core/Image.h"
#include "ImageStream.h"
#include "core/npstring.h"
#include "core/debug.h"

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
		ret = image_create(data, width, height, type);

		char *imageString = image_string_alloc(ret);
		Log(" image loaded ", DEBUG); Log(imageString, DEBUG); Log("\n");
		

		return ret;
	}

	bool ImageStream::WriteImage_STB(const Image * image, const char * filepath)
	{
        //debug log image
		//char strW[15], strH[15], strT[15], type[5];
		//sprintfN(strW, "%ix", image->width); sprintfN(strH, "%i ", image->height); sprintfN(type, "%i ", image->type);
      //  Log("WriteImage_STB: image: ", DEBUG); Log(strW, DEBUG); Log(strH, DEBUG); Log(type, DEBUG);

     //   Log("write to: "); Log(filepath);
		int res = stbi_write_png(filepath, image->width, image->height, image->type, image->data, 0);

		return true;
	}

}

//int main() { return 0;  }

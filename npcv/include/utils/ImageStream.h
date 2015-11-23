#ifndef __NSD_IMAGE_READER__
#define __NSD_IMAGE_READER__

#include "../Image.h"

using namespace npcore;

namespace nputils
{
	class ImageStream
{
public:

	/*
	* STB implementations
	*
	* https://github.com/nothings/stb/stb_image.h
	*
	*/

	// Read from file
	static npcore::Image * ReadImage_STB(const char * filepath);

	// Write to file
	static bool WriteImage_STB(const Image * image, const char * filepath);

};


}


#endif
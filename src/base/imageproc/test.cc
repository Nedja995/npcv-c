#include "base\core\npstdlib.h"
#include "base\imageproc\npimageproc.h"

int npcip_test_imageRW()
{
	NConsolePrint("\n------------\nImage read/write test:\n");

	Image *image = ReadImage_STB("D:\\Projects\\ComputerVision\\npcpure\\examples\\datas\\samples\\lena.jpg");
	WriteImage_STB(image, "D:\\Projects\\ComputerVision\\npcpure\\examples\\datas\\samples\\lenaOut.jpg");

	return 0;
}

int main(int argc, char** argv)
{
	NConsolePrint("\n====================\nNPC Utils Main Test\n=================\n");
	npcip_test_imageRW();
	NConsolePrint("\n====================\nNPC Image Processing Main Test finished\n=================\n");
	return 0;
}
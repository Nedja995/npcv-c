#ifndef __NPCV_EXAMPLES_DATAS
#define __NPCV_DATA_TEST_H__

#include "core/npstring.h"
#include "utils/path_utils.h"



//Windows or Unix
#if defined _MSC_VER
const char *sampleRoot = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\examples\\datas\\";
#else
const char *sampleRoot = "/home/ubuntudev/Desktop/Projects/ComputerVision/npcv/examples/datas/";
#endif

//inputs
const char* fileWriteInput = "Hello\n File test is succesfully";
const char *lenaInput = "samples\\lena.jpg";
const char *ocrSamples = "samples\\digits.png";
const int ocrSubimageSize = 20;
//outputs
const char *fileWriteOutput = "outputs\\FileWriteOutput.txt";
const char *writeOutput = "outputs\\lena.jpg";
const char* grayOutput = "outputs\\gray.png";
const char *subareaOutput = "outputs\\subarea.jpg";
const char* edgeDetectionOutput = "outputs\\edges.png";
const char *ocrSamplesOutput = "outputs\\ocrSamples.csv";



class Examples {
public:
	//
	//Append path and convert
	static char *getPath_alloc(const char *relpath) {
		char *ret = strappendN(sampleRoot, relpath);
#if defined __linux__
		nputils::path_to_linux(ret);
#endif
		return ret;
	}
};


#endif

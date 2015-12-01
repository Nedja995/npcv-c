#ifndef __NPCV_DATA_TEST_H__
#define __NPCV_DATA_TEST_H__

#include "core\npstring.h"
#include "utils\path_utils.h"



//Windows or Unix
#if defined _MSC_VER
const char *sampleRoot = "D:\\Projects\\ComputerVision\\ComputerVision\\npcv\\test\\Datas\\";
#else
const char *sampleRoot = "/home/ubuntudev/Desktop/Projects/ComputerVision/npcv/test/Datas/";
#endif

//inputs
const char* fileWriteInput = "Hello\n File test is succesfully";
const char *lenaInput = "SampleDatas\\lenaa.jpg";
const char *ocrSamples = "SampleDatas\\digits.png";
const int ocrSubimageSize = 20;
//outputs
const char *fileWriteOutput = "TestOutput\\FileWriteOutput.txt";
const char *writeOutput = "TestOutput\\lena.jpg";
const char* grayOutput = "TestOutput\\gray.png";
const char *subareaOutput = "TestOutput\\subarea.jpg";
const char* edgeDetectionOutput = "TestOutput\\edges.png";
const char *ocrSamplesOutput = "TestOutput\\ocrSamples.csv";



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

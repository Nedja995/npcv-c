#ifndef __NPCV_EXAMPLES_DATAS__
#define __NPCV_EXAMPLES_DATAS__

#include "base/core/npstring.h"
#include "base/utils/path_utils.h"



//Windows or Unix

//Examples datas root defined in cmake
const char *project_root = EXAMPLES_DATA_DIR;

//inputs
const char* fileWriteInput = "Hello\n File test is succesfully";
const char *lenaInput = "samples\\lena.jpg";
const char *ocrSamples = "samples\\digits.png";
const int ocrSubimageSize = 20;
//outputs
const char *fileWriteOutput = "output\\FileWriteOutput.txt";
const char *writeOutput = "output\\lena.png";
const char* grayOutput = "output\\gray.png";
const char *subareaOutput = "output\\subarea.png";
const char* edgeDetectionOutput = "output\\edges.png";
const char *ocrSamplesOutput = "output\\ocrSamples.csv";



class Examples {
public:
	//
	//Append path and convert
	static char *getPath_alloc(const char *relpath) {
		char *ret = strappendN(project_root, relpath);
#if defined __linux__
		nputils::path_to_linux(ret);
#else
		nputils::path_to_windows(ret);
#endif
		return ret;
	}
};


#endif

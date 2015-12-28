#ifndef __NPCV_EXAMPLES_DATAS__
#define __NPCV_EXAMPLES_DATAS__

#include "base/core/npstdlib.h"
#include "base/utils/nputils.h"



//Windows or Unix

//Examples datas root defined in cmake
const char *project_root = EXAMPLES_DATA_DIR;

//inputs
const char *fileWriteInput = "Hello\n File test is succesfully";
const char *lenaInput = "samples\\lena.jpg";
const char *gray2input = "samples\\photo3.bmp";
const char *graySimpleInput = "samples\\pic3.png";
const char *ocrSamples = "samples\\digits.png";
const int ocrSubimageSize = 20;
//outputs
const char *fileWriteOutput = "output\\FileWriteOutput.txt";
const char *writeOutput = "output\\lena.png";
const char *grayOutput = "output\\gray.png";
const char *gray2Output = "output\\photo3.bmp";
const char *graySimpleOutput = "output\\pic3.png";
const char *subareaOutput = "output\\subarea.png";
const char *edgeDetectionOutput = "output\\edges.png";
const char *ocrSamplesOutput = "output\\ocrSamples.csv";



class Examples {
public:
	//
	//Append path and convert
	static char *getPath_alloc(const char *relpath) {
		char *ret = strappendN(project_root, relpath);
#if defined __linux__
		path_to_linux(ret);
#else
		path_to_windows(ret);
#endif
		return ret;
	}
};


#endif

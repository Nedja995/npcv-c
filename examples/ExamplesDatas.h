/*
* Copyright (c) 2016 Nedeljko Pejasinovic (nedjaunity@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

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

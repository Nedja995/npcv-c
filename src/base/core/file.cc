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
//#include <fstream>
#include <fstream>
#include "base/core/npstdlib.h"
//#define __cplusplus 1

int file_write(const char * filepath, const char * text)
{
      size_t textLen =  strnlenN((char*)text);
      FILE *fp;

	char textLenTxt[256];
    /*  Log("File Write");
      Log(filepath);

      Log(text);
      sprintfN(textLenTxt, "%i", textLen);
	Log("textLength: "); Log(textLenTxt);*/
     // freeN((void*)textLenTxt);



	fp = fopen(filepath, "wb");

	if(fp == NULL){
         // Log("file can't open !", NP_ERROR);
          return false;
	}


	fwrite(text, sizeof(char), textLen, fp);

	fclose(fp);

	return true;
}

#include "../file_ops.h"

#include <fstream>
#include "../../core/npstdlib/npstring.h"
#include "../../core/npstdlib/debug.h"
//#define __cplusplus 1
using namespace npcore;

namespace nputils
{
	bool file_write(const char * filepath, const char * text)
	{
        size_t textLen =  npcore::string_length((char*)text);
        FILE *fp;

        char textLenTxt[256];
        Log("File Write");
        Log(filepath);

        Log(text);
        sprintfN(textLenTxt, "%i", textLen);
		Log("textLength: "); Log(textLenTxt);
       // freeN((void*)textLenTxt);



		fp = fopen(filepath, "wb");

		if(fp == NULL){
            Log("file can't open !", ERROR);
            return false;
		}


		fwrite(text, sizeof(char), textLen, fp);

		return true;
	}

}

#include "../file_ops.h"

#include <fstream>
#include "../../core/npstdlib/string.h"
#include "../../core/npstdlib/debug.h"
#define __cplusplus 1
using namespace npcore;

namespace nputils
{
	bool file_write(const char * filepath, const char * text)
	{
        size_t textLen =  npcore::string_length((char*)text);
        FILE *fp;

        char textLenTxt[256];
        Log("\nFile Write\n");
        Log(filepath);
        Log("\n");
        Log(text);
        sprintfN(textLenTxt, "%i", textLen);
		Log("\ntextLength: "); Log(textLenTxt);
       // freeN((void*)textLenTxt);



		fp = fopen(filepath, "wb");

		if(fp == NULL){
            Log("\nfile can't open !", ERROR);
            return false;
		}


		fwrite(text, sizeof(char), textLen, fp);

		return true;
	}

}

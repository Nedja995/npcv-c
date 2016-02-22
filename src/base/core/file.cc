
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

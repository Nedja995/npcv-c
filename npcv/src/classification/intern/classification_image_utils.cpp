#include "../../core/npstdlib/npstdlib.h"
#include "../../core/npstdlib/string.h"

#include "../classification_image_utils.h"
#include "file_ops.h"

#include <stdlib.h>

#define MAX_REGION_VALUE_CHARS 4


namespace npcf
{
	bool csv_write_image_classifier(ImageClassificationData * icd, const char * filepath)
	{
		char * text = (char *)mallocN(sizeof(char) * 4 * icd->regionCount +1);
		int regVal = 0;
		for (int i = 0; i < icd->regionCount; i++)
		{
			regVal = image_classify_region_get(icd, i);
			//sprintfN(text + i * sizeof(char) * 4, "%i,%i\n", 0, regVal);
		}

		nputils::file_write(filepath, text);

		return false;
	}

	char *csv_write_image_classifiers(npcore::List * classifiersList, const char * filepath)
	{
		int listCount = npcore::list_count(classifiersList);
		int regCount = ((ImageClassificationData*)classifiersList->first->data)->regionCount;

		char *textValue = (char *)mallocN((sizeof(char) * MAX_REGION_VALUE_CHARS));
		char *textClass = (char *)mallocN((sizeof(char) * MAX_REGION_VALUE_CHARS * 2) * regCount);
		char *textAllClass = (char *)mallocN(sizeof(char) * MAX_REGION_VALUE_CHARS * regCount * listCount + 1);

		int regVal = 0;
		size_t offset = 0;
		size_t offsetReg = 0;
		char *fmtTemp = 0;

		int j = 0;
		for (npcore::LinkData *iter = classifiersList->first; 
				iter != classifiersList->last; 
				iter = iter->next){

			offsetReg = 0;
			for (int i = 0; i < regCount; i++)
			{
				regVal = image_classify_region_get((ImageClassificationData*)iter->data, i);
				if (regVal == -1)
					int a = 3;
				sprintf(textValue, "%i", regVal);
				//printf("%i", regVal);
				if (i == regCount - 1) {
					sprintf(textClass + offsetReg, "%i", regVal);
					offsetReg += npcore::strnlen(textValue) ;
				}					
				else {
					sprintf(textClass + offsetReg, "%i,", regVal);
					offsetReg += npcore::strnlen(textValue) + 1;
				}			
			}

			sprintf(textAllClass + offset, "%s\n", textClass);

			if (j++ == 0) {}
			else
				offset += offsetReg + sizeof(char);
		}
		nputils::file_write(filepath, textAllClass);

		return textAllClass;
	}

}
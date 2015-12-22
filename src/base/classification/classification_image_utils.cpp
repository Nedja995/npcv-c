#include "base/core/npio.h"
#include "base/core/npstring.h"

#include "classification_image_utils.h"
#include "base/utils/file_ops.h"


#define MAX_IMAGE_CLASSDATA_TEXT 1024

#define MAX_REGION_VALUE_CHARS 4

	char *data_get_format_csv(ImageClassificationData * icd, size_t *stringLength)
	{
		char *ret = (char*)mallocN(sizeof(char) * MAX_IMAGE_CLASSDATA_TEXT);
		*ret = '\0';
		char *textValue = (char *)mallocN((sizeof(char) * MAX_REGION_VALUE_CHARS));
		*textValue = '\0';

		size_t offsetReg = 0;
		int regVal = 0;
		for (int i = 0; i < icd->regionCount; i++)
		{
			regVal = image_classify_region_get(icd, i);
			if (regVal == -1)
				int a = 3;
			sprintf(textValue, "%i", regVal);
			//printf("%i", regVal);
			if (i == icd->regionCount - 1) {
				sprintf(ret + offsetReg, "%i", regVal);
				offsetReg += npcore::strnlenN(textValue);
			}
			else {
				sprintf(ret + offsetReg, "%i,", regVal);
				offsetReg += npcore::strnlenN(textValue) + 1;
			}
		}
		freeN(textValue);
		*stringLength = offsetReg;

		return ret;
	}

	char *datas_get_format_csv(List *classifiersList)
	{
		ImageClassificationData *icdIter = NULL;
		int regVal = 0;
		size_t offset = 0;
		size_t offsetReg = 0;

		int listCount = npcore::list_count(classifiersList);
		int regCount = ((ImageClassificationData*)classifiersList->first->data)->regionCount;

	//	char *textValue = NULL;
		char *textClass = NULL;// (char *)mallocN((sizeof(char) * MAX_REGION_VALUE_CHARS * 2) * regCount);
		char *textAllClass = (char *)mallocN(sizeof(char) * MAX_REGION_VALUE_CHARS * regCount * listCount + 1);



		int i = 0;
		LIST_FOREACH(classifiersList) {
			offsetReg = 0;
			icdIter = (ImageClassificationData*)link->data;
			textClass = data_get_format_csv(icdIter, &offsetReg);

			sprintfN(textAllClass + offset, "%s\n", textClass);
			freeN(textClass);
			offset += offsetReg + sizeof(char);
		}
		//freeN(textClass);
	//	nputils::file_write(filepath, textAllClass);

		return textAllClass;
	}


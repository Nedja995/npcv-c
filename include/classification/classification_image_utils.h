#ifndef __NPCV_CLASSF_FILE_H__
#define __NPCV_CLASSF_FILE_H__


#include "classification/image_classification.h"

#include "core/list.h"

using namespace npcore;

namespace npcf
{
	char *data_get_format_csv(ImageClassificationData *icd, size_t *stringLength);

	char *datas_get_format_csv(List *classifiersList);


}


#endif
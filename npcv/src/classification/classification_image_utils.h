#ifndef __NPCV_CLASSF_FILE_H__
#define __NPCV_CLASSF_FILE_H__


#include "../classification/image_classification.h"

#include "../core/npstdlib/list.h"

using namespace npcore;

namespace npcf
{
	bool csv_write_image_classifier(ImageClassificationData *icd, const char *filepath);

	char *csv_write_image_classifiers(List *classifiersList, const char *filepath);


}


#endif
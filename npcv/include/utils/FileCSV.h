#ifndef __NPCV_CSV_STREAM_H__
#define __NPCV_CSV_STREAM_H__


#include "classification\image_classification.h"

#include "../../include/core/list.h"

using namespace npcore;
using namespace npcf;

namespace nputils
{
	bool csv_write_image_classifier(ImageClassificationData *icd, const char *filepath);

	bool csv_write_image_classifiers(List *classifiersList, const char *filepath);


}


#endif
#ifndef __NPCV_IMAGE_CLASSIFICATION_H__
#define __NPCV_IMAGE_CLASSIFICATION_H__

#include "../core/Image.h";

using namespace npcore;

namespace npcf {

	struct ImageClassificationData 
	{
		int regionCount;

		// Array of regions value
		// "-1" is separator betwen regions
		int * regionsDatas;
	};

	ImageClassificationData * image_classification_data_create(int regionsCount);

	bool image_classify_region_set(ImageClassificationData *icd, int region, int val);

	bool image_classify_region_add(ImageClassificationData *icd, int region, int val);

	int image_classify_region_get(ImageClassificationData *icd, int region);

	ImageClassificationData * image_classify(Image * image, int region);


}


#endif
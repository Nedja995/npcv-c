
#include "image_classification.h"
#include "base/core/npstdlib.h"
#include <math.h>

	ImageClassificationData * image_classification_data_create(int regionsCount)
	{
		ImageClassificationData * ret = (ImageClassificationData *)mallocN(sizeof(ImageClassificationData));

		ret->regionCount = regionsCount;

		size_t memSize = sizeof(int) * regionsCount * 2;
		ret->regionsDatas = (int *)mallocN(memSize);

		for (int i = 0; i < regionsCount * 2; i++)
			if (i ^ 2 == 0)
				memsetN(ret->regionsDatas + i, 0, sizeof(int));
			else
				memsetN(ret->regionsDatas + i, 0, sizeof(int));
		return ret;
	}
	
	void free_image_classification_data(ImageClassificationData * data)
	{
		freeN(data->regionsDatas);
		freeN(data);
	}

	bool image_classify_region_set(ImageClassificationData *icd, int region, int val)
	{
		if (region > icd->regionCount)
			return false;

		*(icd->regionsDatas + region) = val;
		return true;
	}

	bool image_classify_region_add(ImageClassificationData * icd, int region, int val)
	{
		if (region > icd->regionCount)
			return false;

		*(icd->regionsDatas + region) += val;
		return true;
	}

	int image_classify_region_get(ImageClassificationData *icd, int region)
	{
		if (region > icd->regionCount)
			return -1;
		if (*(icd->regionsDatas + region) == -1)
			int a = 7;
		return *(icd->regionsDatas + region);
	}

	ImageClassificationData * image_classify(Image * edges, int region)
	{
		if (edges == NULL)
		{
			NConsolePrint("No Image");
			return NULL;
		}

		//region size
		float sizeCoef = sqrtf((float)region);
		size_tt regionSize = edges->width / sizeCoef;
		int rows = fabs(sizeCoef);

		ImageClassificationData * ret = image_classification_data_create(region);

		//temp
		Image * regionImg = NULL;
		Pixel * px = NULL;
		int regIt = 0;

		for (int x = 0; x < rows * regionSize; x++)
		{
			for (int y = 0; y < rows * regionSize; y++)
			{
				px = image_get_pixel(edges, x, y);
				regIt = 0;
				regIt += (int)(x / regionSize);
				regIt += (int)(y / regionSize);

				image_classify_region_add(ret, regIt, (px->b == 0) ? 0 : 1);
				
				freeN(px);
			}

		}
		return ret;
	}

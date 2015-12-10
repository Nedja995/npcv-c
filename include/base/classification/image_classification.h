/**
*  \brief Main image classification functions
*
*  \file image_classification.h
*
*  \ingroup classification
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NPCV_IMAGE_CLASSIFICATION_H__
#define __NPCV_IMAGE_CLASSIFICATION_H__

#include "../core/Image.h";

using namespace npcore;

namespace npcf {

	struct ImageClassificationData 
	{
		int regionCount;	/**< Number of regions */
		int * regionsDatas; /**< Array of regions value. "-1" is separator betwen regions */
	};

	/**
	 * @brief	Classify based on regions
	 *
	 * Based on counting edge pixels per regions
	 * 
	 * @param	regionsCount	Number of regions.
	 * @return	null if it fails, else an new ImageClassificationData.
	 */
	ImageClassificationData * image_classification_data_create(int regionsCount);
	
	void free_image_classification_data(ImageClassificationData * data);

	/**
	 * @brief	Set region value.
	 *  
	 *
	 * @param [in,out]	    icd.
	 * @param	region	   	The region.
	 * @param	val		   	The value.
	 * @return	true if it succeeds, false if it fails.
	 */
	bool image_classify_region_set(ImageClassificationData *icd, int region, int val);

	/**
	 * @brief	Add region with value to existing icd.
	 *
	 * @param [in,out]	icd	If non-null, the icd.
	 * @param	region	   	The region.
	 * @param	val		   	The value.
	 * @return	true if it succeeds, false if it fails.
	 */
	bool image_classify_region_add(ImageClassificationData *icd, int region, int val);

	/**
	 * @brief	Get region value from datas.
	 *
	 * @param [in,out]	icd	If non-null, the icd.
	 * @param	region	   	The region.
	 * @return	An int.
	 */
	int image_classify_region_get(ImageClassificationData *icd, int region);

	/**
	 * @brief  Classify gray image based on edges.
	 *
	 * @param [in,out]	image	If non-null, the image.
	 * @param	region		 	The region.
	 * @return	null if it fails, else an ImageClassificationData*.
	 */
	ImageClassificationData * image_classify(Image * image, int region);


}


#endif

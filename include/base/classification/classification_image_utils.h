/**
*  \brief Helper utils for image classification
*
*  Contain utilities to handle and process
*	image classified datas
*
*  \file classification_image_utils.h
*
*  \ingroup classification
*
*  \author Nedeljko Pejasinovic
*
*/
#ifndef __NPCV_CLASSF_FILE_H__
#define __NPCV_CLASSF_FILE_H__

#include "base/classification/image_classification.h"

#include "base/core/list.h"

using namespace npcore;

/**
 * @namespace	npcf
 *
 * @brief	Classification namespace
 */
namespace npcf
{
	/**
	 * @brief	Make csv string of ImageClassificationData
	 *
	 * @param [in,out]	icd				If non-null, the icd.
	 * @param [in,out]	stringLength	If non-null, length of the string.
	 * @return	null if it fails, else pointer to new string.
	 */
	char *data_get_format_csv(ImageClassificationData *icd, size_t *stringLength);

	/**
	 * @brief	Make csv string of array of ImageClassificationData.
	 *
	 * @param [in,out]	classifiersList	If non-null, list of classifiers.
	 * @return	null if it fails, else pointer to new string.
	 */
	char *datas_get_format_csv(List *classifiersList);


}


#endif
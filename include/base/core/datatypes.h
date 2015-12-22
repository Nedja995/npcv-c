#ifndef __NSDK_DATATYPES_H__
#define __NSDK_DATATYPES_H__
/**
*  @brief Base data types.
*  @brief Platform dependet

*  @file datatypes.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*/	
#ifdef __cplusplus
extern "C" {
#endif

#define NULL 0

	/**************************************
	*		Defines for Windows & Linux
	*/
#if defined _MSC_VER || defined __linux__
	/** @typedef unsigned char uchar.*/
	typedef unsigned char uchar;
	typedef unsigned short ushort;
	typedef unsigned int size_tt;
#endif

	/**************************************
	*		Defines for Linux
	*/
#if defined __linux__
//#   include "stdlib.h"
#elif defined _MSC_VER
	/***************************************
	*		Defines for Windows
	*/
#endif

#ifdef __cplusplus
}
#endif

#endif

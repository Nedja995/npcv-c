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


/**@typedef	unsigned short ushort*/
typedef unsigned short ushort;

/**************************************
*		Defines for Windows & Linux
*/
#if defined _MSC_VER || defined __linux__
	/** @typedef unsigned char uchar.*/
	typedef unsigned char uchar;
#endif

/**************************************
*		Defines for Linux
*/
#if defined __linux__
#   include "stdlib.h"
#elif defined _MSC_VER
/***************************************
*		Defines for Windows
*/
#endif



#endif

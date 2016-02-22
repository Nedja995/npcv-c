/*
* Copyright (c) 2016 Nedeljko Pejasinovic (nedjaunity@gmail.com)
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
* LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
* OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
* WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

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

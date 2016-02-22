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


#include "npmemory.h"



#if defined _MSC_VER || defined __linux__
//+/////////////////////////////////-+-+-+-+
//	Windows and Linux headers
//
//#	include <stdio.h>
//#	include "stdlib.h"
#endif//+/////////////////////////////////-+

#if defined _MSC_VER
//+/////////////////////////////////-+-+-+-+
//	Windows headers
//
#include <stdlib.h>
#include <string.h>
#else defined __linux__//-+-+-+-+-+-+-+
//+/////////////////////////////////-+-+-+-+
//	Linux headers
//
//#   include <string.h>
#endif//+/////////////////////////////////-+

void * mallocN(size_tt size)
{
	void* ret = 0;

#if _MSC_VER || __linux__
	//-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Windows and Linux malloc
	// 
	ret = malloc(size);
#endif

	return ret;
}


void memcpyN(void * dst,
	void * src,
	size_tt size)
{
#if _MSC_VER || __linux__
	//-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Windows and Linux memory copy
	// 
	dst = memcpy(dst, src, size);
#endif
}

/**
* @brief	Set memory.
* @param [in,out]	mem	 Pointer to memory.
* @param	val		   	The value.
* @param	size	   	The size.
*/
void memsetN(void * mem, int val, size_tt size)
{
#if _MSC_VER || __linux__
	//-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Windows and Linux memory set
	// 
	memset(mem, val, size);
#endif

}

void free_pointer(void **ptr)
{
	if (*ptr == NULL) {
		//npcore::NLogError("NULL pointer passed to free");
	}
	else {
#if _MSC_VER || __linux__
		//-+-+-+-+-+-+-+-+-+-+-+-+-+
		// Windows and Linux free
		// 
		free(*ptr);
		free(ptr);
		*ptr = NULL;
		ptr = NULL;
#endif
	}
}

/**
* @brief	Free memory.
* @param [in,out]	data	Pointer to data.
*/
void freeN(void * data)
{
	if (data == NULL) {
		//npcore::NLogError("NULL pointer passed to free");
	}
	else {
#if _MSC_VER || __linux__
		//-+-+-+-+-+-+-+-+-+-+-+-+-+
		// Windows and Linux free
		// 
		free(data);
		data = NULL;
#endif

	}
}

/**
* @brief	Duplicate memory.
* @param [in,out]	src	If non-null, source for the.
* @param	size	   	The size.
* @return	null if it fails, else pointer to new memory.
*/
void* duplicateN(void * src,
	size_tt size)
{
	void * dst = mallocN(size);
	memcpyN(dst, src, size);

	return dst;
}

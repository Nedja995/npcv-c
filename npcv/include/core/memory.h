#ifndef __NSDK_MEMORY_H__
#define __NSDK_MEMORY_H__


/*
* Platform specific include
*
*/

//
//Windows and Linux shared
#if defined _MSC_VER || defined __linux__
#	include <stdio.h>
#	include "stdlib.h"
#endif

//
//Specific
#if defined _MSC_VER
#	include <string>
#else defined __linux__
#   include <string.h>
#endif

//
// COMPILER DEPENDED
// Memory allocation
//
inline void* mallocN(size_t size)
{
	void* ret = 0;

#if defined _MSC_VER || !_MSC_VER
	//
	// Visual Studio
	//
	ret = malloc(size);
#endif

	return ret;
}

//
// Faster generic allocation function
// TODO: speed up casting
//
template<typename T>
inline T* mallocN()
{
	T* ret = 0;

	ret = (T*)mallocN(sizeof(T));

	return ret;
}

inline void memcpyN(void * dst,
			 void * src,
			 size_t size)
{
#ifdef _MSC_VER || !_MSC_VER
	//
	// Visual Studio
	//
	dst = memcpy(dst, src, size);
#endif
}

inline void memsetN(void * mem, int val, size_t size)
{
	memset(mem, val, size);
}


inline void freeN(void * data)
{
	free(data);
	data = NULL;
}





inline void* duplicateN(void * src,
						size_t size)
{
	void * dst = mallocN(size);
	memcpyN(dst, src, size);
	return dst;
}

//end of __NSDK_MEMORY_H__
#endif

#ifndef __NSDK_MEMORY_H__
#define __NSDK_MEMORY_H__
/**
*  @brief Memory functions
*
*  @file memory.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*
*/
#define NULL 0

#if defined _MSC_VER || defined __linux__
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	Windows and Linux headers
//
#	include <stdio.h>
#	include "stdlib.h"
#endif//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#if defined _MSC_VER
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	Windows headers
//
#	include <string>
#else defined __linux__//-+-+-+-+-+-+-+
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	Linux headers
//
#   include <string.h>
#endif//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// projects headers
// 
#include "debug.h" //for NLogError
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#if defined _MSC_VER && defined _DEBUG && false
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Windows CRT debuging
// 
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>=
/**
 * @def	malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
 *
 * @brief	Windows CRT debuging macro
 * 
 * @todo	This is defined in included crtdbg.h
 * 			but don't work for some case
 * 
 * @param	sizes	size_t.
 */
#define malloc(size) _malloc_dbg(size, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

/**
 * @brief	Allocate memory.
 * @param	size	Number of bytes.
 * @return	null if it fails, pointer to new allocated memory.
 */
inline void* mallocN(size_t size)
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

/**
 * @brief	Faster generic allocation function.
 * @param	T	Generic type parameter.
 * @return	null if it fails, else a T*.
 
template<typename T>
inline T* mallocN()
{
	T* ret = 0;

	ret = (T*)mallocN(sizeof(T));

	return ret;
}*/

inline void memcpyN(void * dst,
			 void * src,
			 size_t size)
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
inline void memsetN(void * mem, int val, size_t size)
{
#if _MSC_VER || __linux__
	//-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Windows and Linux memory set
	// 
	memset(mem, val, size);
#endif

}

inline void free_pointer(void **ptr)
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
inline void freeN(void * data)
{
	if(data == NULL){
		//npcore::NLogError("NULL pointer passed to free");
	}
	else{
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
inline void* duplicateN(void * src,
						size_t size)
{
	void * dst = mallocN(size);
	memcpyN(dst, src, size);

	return dst;
}

#endif

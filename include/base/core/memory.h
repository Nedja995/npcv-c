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


/**************************************
*	Includes for Windows & Linux
*/
#if defined _MSC_VER || defined __linux__
#	include <stdio.h>
#	include "stdlib.h"
#endif

#if defined _MSC_VER
/**************************************
*		Defines for Windows
*/
#	include <string>
#else defined __linux__
/**************************************
*		Defines for Linux
*/
#   include <string.h>
#endif

/**
 * @brief	Allocate memory.
 * @param	size	Number of bytes.
 * @return	null if it fails, pointer to new allocated memory.
 */
inline void* mallocN(size_t size)
{
	void* ret = 0;

#if _MSC_VER || __linux__
	/**************************************
	*		Defines for Windows & Linux
	*/
	ret = malloc(size);
#endif

	return ret;
}

/**
 * @brief	Faster generic allocation function.
 * @param	T	Generic type parameter.
 * @return	null if it fails, else a T*.
 */
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
#if _MSC_VER || __linux__
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
	memset(mem, val, size);
}

/**
 * @brief	Free memory.
 * @param [in,out]	data	Pointer to data.
 */
inline void freeN(void * data)
{
	free(data);
	data = NULL;
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

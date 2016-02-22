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
#ifdef __cplusplus
extern "C" {
#endif


#include "datatypes.h"

//	NPC_DATATYPES


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// projects headers
// 
//#include "debug.h" //for NLogError
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//#if defined _MSC_VER && defined _DEBUG && -1
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// Windows CRT debuging
// 
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>=
/**
 * @def	malloc(s) _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
 *
 * @brief	Windows CRT debuging macro
 *
 * @todo	This is defined in included crtdbg.h
 * 			but don't work for some case
 *
 * @param	sizes	size_tt.
 */
//#define malloc(size) _malloc_dbg(size, _NORMAL_BLOCK, __FILE__, __LINE__)
//#endif //+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-



 /**
  * @brief	Allocate memory.
  * @param	size	Number of bytes.
  * @return	null if it fails, pointer to new allocated memory.
  */
	void * mallocN(size_tt size);


	void memcpyN(void * dst,
		void * src,
		size_tt size);

	/**
	 * @brief	Set memory.
	 * @param [in,out]	mem	 Pointer to memory.
	 * @param	val		   	The value.
	 * @param	size	   	The size.
	 */
	void memsetN(void * mem, int val, size_tt size);

	void free_pointer(void **ptr);

	/**
	 * @brief	Free memory.
	 * @param [in,out]	data	Pointer to data.
	 */
	void freeN(void * data);

	/**
	 * @brief	Duplicate memory.
	 * @param [in,out]	src	If non-null, source for the.
	 * @param	size	   	The size.
	 * @return	null if it fails, else pointer to new memory.
	 */
	void* duplicateN(void * src,
		size_tt size);

#ifdef __cplusplus
}
#endif

#endif

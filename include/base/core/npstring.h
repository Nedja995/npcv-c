/**
*  @brief String functions
*
*  @file npstring.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*/
#ifndef __NPCORE_STRING__
#define __NPCORE_STRING__

#include "datatypes.h"
#include "memory.h"

/**@brief	A macro that defines string buffer. */
#define STRING_BUFFER 1024

/**
 * @brief	Macro for string allocation.
 * 			
 * @param	length	The length.
 */
#define string_alloc(length) (char *)mallocN(sizeof(char) * length + 1)

namespace npcore
{
	/**
	 * @brief	Make formated string.
	 * 			
	 * @param	fmt	Describes the format to use.
	 * @param	...	Variable arguments providing additional information.
	 * @return	null if it fails, else pointer to new string.
	 */
	char *strmakeN(const char *fmt, ...);

	/**
	 * @brief	String length.
	 * 			
	 * @param	string	The string.
	 * @return	Number of chars in string.
	 */
	size_t strnlenN(const char *string);

	/**
	 * @brief	sptrinf.
	 * 			
	 * @param [in,out]	buf	If non-null, the buffer.
	 * @param	fmt		   	Describes the format to use.
	 * @param	...		   	Variable arguments providing additional information.
	 */
	void sprintfN(char *buf, const char *fmt, ...);

	/**
	 * @brief	Replace characters in string.
     *
	 * @param [in,out]	string	If non-null, the string.
	 * @param [in,out]	from  	If non-null, source for the.
	 * @param [in,out]	to	  	If non-null, to.
	 */
	void strreplaceN(char *string, char *from, char *to);

	/**
	 * @brief	Append string to string.
	 *
	 * @param	first 	The first.
	 * @param	second	The second.
	 * @return	null if it fails, else pointer to new string.
	 */
	char *strappendN(const char *first, const char *second);

}
#endif

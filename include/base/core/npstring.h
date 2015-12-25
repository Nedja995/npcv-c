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
//#include "npmemory.h"

/**@brief	A macro that defines string buffer. */
#define STRING_BUFFER 1024

/**
 * @brief	Macro for string allocation.
 * 			
 * @param	length	The length.
 */
#define string_alloc(length) (char *)mallocN(sizeof(char) * length + 1)

#ifdef __cplusplus
extern "C" {
#endif

//	NPC_DATATYPES

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
	size_tt strnlenN(const char *string);

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

	/**
	 * @brief	Nstrdups the given string.
	 * @param	string	The string.
	 *
	 * @return	null if it fails, else a char*.
	 */
	char *stringDuplicate(const char *string);

	/**
	 * @brief	String compare.
	 * 			
	 * @param	string			The string.
	 * @param	stringSecond	The string second.
	 *
	 * @return	An int.
	 */
	int stringCompare(const char *string, const char *stringSecond);

	/**
	 * @brief	String contains.
	 *
	 * @param	string  	The string.
	 * @param	sequence	The sequence.
	 *
	 * @return	Pointer to sequience in string.
	 */
	const char *stringContains(const char *string, const char *sequence);

#ifdef __cplusplus
}
#endif
#endif

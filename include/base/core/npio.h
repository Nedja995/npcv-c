/**
*  @brief Standard input/output.
*  		  
*  @file npio.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*/
#ifndef __NSDK_STD_LIB_H__
#define __NSDK_STD_LIB_H__

#define _CRT_SECURE_NO_WARNINGS

#define NULL 0

namespace npcore {

	/**
	 * @brief	Console print.
	 * 			
	 * @param	fmt	Describes the format to use.
	 * @param	...	Variable arguments providing additional information.
	 */
	void NConsolePrint(const char *fmt, ...);

	/**
	 * @brief	Console input.
	 * 			
	 * @param	fmt	Describes the format to use.
	 * @param	...	Variable arguments providing additional information.
	 *
	 * @return	input from console.
	 */
	int NConsoleInput(const char *fmt, ...);
}



#endif

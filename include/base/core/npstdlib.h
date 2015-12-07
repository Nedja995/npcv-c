/**
*  @brief Standard include for npcv
*
*  @file npstdlib.h
*
*  @ingroup core
*
*  @author Nedeljko Pejasinovic
*/
#ifndef __NP_STDLIB_H__
#define __NP_STDLIB_H__

#include "datatypes.h"
#include "mathn.h"
#include "debug.h"
#include "Image.h"
#include "list.h"
#include "memory.h"
#include "npio.h"
#include "npstring.h"
#include "ntime.h"

namespace npcore {

	/**
	 * @brief	Initialize NPCORE.
	 * @return	If sucessfully 1 else -1.
	 */
	int NPCORE_initialize();

	/**
	* @brief	exit NPCORE.
	* @return	If sucessfully 1 else -1.
	*/
	int NPCORE_exit();

}

#endif
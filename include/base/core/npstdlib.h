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

#include "list.h"
#include "npmemory.h"
#include "npio.h"
#include "npstring.h"
#include "ntime.h"
#include "npfile.h"
#include "npmath.h"

#ifdef __cplusplus
extern "C"{
#endif
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


#ifdef __cplusplus
}
#endif
#endif
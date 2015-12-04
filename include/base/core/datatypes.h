#ifndef __NSDK_DATATYPES_H__
#define __NSDK_DATATYPES_H__

//DWORK in windows
typedef unsigned short ushort;

#if defined _MSC_VER || defined __linux__
	typedef unsigned char uchar;
#endif

//for size_T
#if defined __linux__
#   include "stdlib.h"
#endif



#endif

#
#	CORE
#
# Core project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)
	
set(CORE_INC_DIR 
	${PROJECT_INCLUDE}/base/core)
	
set(CORE_INC
	${CORE_INC_DIR}/list.h

	${CORE_INC_DIR}/npio.h
	${CORE_INC_DIR}/npstring.h
	${CORE_INC_DIR}/npmemory.h
	${CORE_INC_DIR}/debug.h
	${CORE_INC_DIR}/datatypes.h
	${CORE_INC_DIR}/ntime.h
	${CORE_INC_DIR}/npstdlib.h
	${CORE_INC_DIR}/npfile.h
	${CORE_INC_DIR}/npfmath.h
)

set(CORE_SRC
	list.cc
	memory.cc
	io.cc
	debug.cc
	string.cc
	time.cc
	stdlib.cc
	test.cc
	file.cc
	math.cc
)

#include project headers
include_directories(core ${PROJECT_INCLUDE})
#include headers
include_directories(core ${CORE_INC_DIR})

# Library Add
add_library(core STATIC ${CORE_SRC} ${CORE_INC})

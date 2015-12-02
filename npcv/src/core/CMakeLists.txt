#
#	CORE
#
# Core project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)
	
set(CORE_INC_DIR 
	${PROJECT_INCLUDE}/core)
	
set(CORE_INC
	${CORE_INC_DIR}/pixel.h
	${CORE_INC_DIR}/Image.h
	${CORE_INC_DIR}/list.h
	${CORE_INC_DIR}/mathn.h
	${CORE_INC_DIR}/npio.h
	${CORE_INC_DIR}/npstring.h
	${CORE_INC_DIR}/memory.h
	${CORE_INC_DIR}/debug.h
	${CORE_INC_DIR}/datatypes.h
	${CORE_INC_DIR}/ntime.h
)

set(CORE_SRC
	pixel.cpp
	Image.cpp
	list.cpp
	mathn.cpp
	npio.cpp
	debug.cpp
	npstring.cpp
	ntime.cpp
)

#include project headers
include_directories(core ${PROJECT_INCLUDE})
#include headers
include_directories(core ${CORE_INC_DIR})

# Library Add
add_library(core STATIC ${CORE_SRC} ${CORE_INC})

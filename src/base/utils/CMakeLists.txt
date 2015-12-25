#
#	UTILS
#
# UTILS project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(UTILS_INC_DIR
	${PROJECT_INCLUDE}/base/utils
)
set(UTILS_INC
	${UTILS_INC_DIR}/path_utils.h
	${UTILS_INC_DIR}/nputils.h

)
set(UTILS_SRC
	path_utils.cc
	test.cc
)



#include project headers
include_directories(utils ${PROJECT_INCLUDE})
#include headers
include_directories(utils ${UTILS_INC_DIR})



# Library Add
add_library(utils STATIC ${UTILS_SRC} ${UTILS_INC})

#link with core lib
target_link_libraries(utils core)



#
#END UTILS
#####################################################################################

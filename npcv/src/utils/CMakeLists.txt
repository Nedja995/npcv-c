#
#	UTILS
#
# UTILS project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(UTILS_INC_DIR
	${PROJECT_INCLUDE}/utils
)
set(UTILS_INC
	${UTILS_INC_DIR}/file_ops.h
	${UTILS_INC_DIR}/ImageStream.h
)
set(UTILS_SRC
	file_ops.cpp
	ImageStream.cpp
)

###################
# EXTERNAL DEP
#
# STB_IMAGE
set(STB_IMAGE_INC
	${CMAKE_SOURCE_DIR}/lib/stb/stb_image.h
	${CMAKE_SOURCE_DIR}/lib/stb/stb_image_write.h
)

#include project headers
include_directories(utils ${PROJECT_INCLUDE})
#include headers
include_directories(utils ${UTILS_INC_DIR})
#
# external STB_IMAGE 
if(STB_IMAGE)
	#preprocessor
	add_definitions(-DWITH_STB)
	#include stb_image headers
	include_directories(utils ${CMAKE_SOURCE_DIR}/lib/stb)
	
endif()

# Library Add
add_library(utils ${UTILS_SRC} ${UTILS_INC})

#link with core lib
target_link_libraries(utils core)



#
#END UTILS
#####################################################################################

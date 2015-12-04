#
#	IMAGEPROC
#
# Image Processing library project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)


set(IMAGEPROC_INC_DIR 
	${PROJECT_INCLUDE}/base/imageproc
)
set(IMAGEPROC_INC
	${IMAGEPROC_INC_DIR}/edge_detection.h
	${IMAGEPROC_INC_DIR}/imageproc_gray.h
)
set(IMAGEPROC_SRC
	EdgeDetection.cpp
	ImageProc_Gray.cpp
)


if(MODULE_IMGPROC)
	#include core headers
	include_directories(imageproc ${PROJECT_INCLUDE})
	# Library project
	add_library(imageproc ${IMAGEPROC_SRC} ${IMAGEPROC_INC})
	#include headers
	include_directories(core ${IMAGEPROC_INC_DIR})
	#link libraries
	target_link_libraries(imageproc core)
	target_link_libraries(imageproc utils)
endif()


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
	${IMAGEPROC_INC_DIR}/pixel.h
	${IMAGEPROC_INC_DIR}/image.h
	${IMAGEPROC_INC_DIR}/edge_detection.h
	${IMAGEPROC_INC_DIR}/imageproc_gray.h
	${IMAGEPROC_INC_DIR}/convolution_matrix.h
	${IMAGEPROC_INC_DIR}/npimage_utils.h
)
set(IMAGEPROC_SRC
	pixel.cc
	image.cc
	EdgeDetection.cc
	ImageProc_Gray.cc
	image_utils.cc
	convolution_matrix.cc
	test.cc
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


###################
# EXTERNAL DEP
#
# STB_IMAGE
set(STB_IMAGE_INC
	${CMAKE_SOURCE_DIR}/lib/stb/stb_image.h
	${CMAKE_SOURCE_DIR}/lib/stb/stb_image_write.h
)

if(WITH_STB_IMAGE)
	#preprocessor
	add_definitions(-DWITH_STB_IMAGE)
	#include stb_image headers
	include_directories(imageproc ${CMAKE_SOURCE_DIR}/lib/stb)	
endif()
#
# external STB_IMAGE 

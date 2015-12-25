#
#	CLASSIFICATION
#
# library project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(CLASSIFICATION_INC_DIR
	${PROJECT_INCLUDE}/base/classification
)

set(CLASSIFICATION_INC
	${CLASSIFICATION_INC_DIR}/image_classification.h
	${CLASSIFICATION_INC_DIR}/classification_image_utils.h
)

set(CLASSIFICATION_SRC
	image_classification.cc
	classification_image_utils.cc
)

if(MODULE_CLASSIFICATION)
	#include project headers
	include_directories(classification ${PROJECT_INCLUDE})
	#include headers
	include_directories(core ${CLASSIFICATION_INC_DIR})
	# Library Add
	add_library(classification STATIC ${CLASSIFICATION_SRC} ${CLASSIFICATION_INC})
	#link with core lib
	target_link_libraries(classification core)
endif()


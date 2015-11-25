
add_subdirectory(core)
add_subdirectory(utils)
#add_subdirectory(imageproc)
#add_subdirectory(classification)


#
#	CORE
#
# Core project
#
set(INC_CORE
	.
)
set(INC_SYS_CORE
	core/pixel.h
	core/Image.h
	
	#npstdlib
	core/npstdlib/list.h
	core/npstdlib/mathn.h
	core/npstdlib/npstdlib.h
	core/npstdlib/string.h
	core/npstdlib/memory.h
	#core/npstdlib/xprintf.h

)

set(STB_IMAGE_INC
	../lib/stb/stb_image.h
	../lib/stb/stb_image_write.h
)
if(STB_IMAGE)
	set(INC_SYS_CORE
		${INC_SYS_CORE}
		../lib/stb/
	)
endif()

set(SRC_CORE
	core/intern/pixel.cpp
	core/intern/Image.cpp
	
	#npstdlib
	core/intern/npstdlib/list.cpp
	core/intern/npstdlib/mathn.cpp
	core/intern/npstdlib/npstdlib.cpp

	core/intern/npstdlib/string.cpp

	#core/intern/npstdlib/xprintf.cpp
	
)

add_library(core ${SRC_CORE} ${INC_SYS_CORE})


#
#END CORE
#####################################################################################

#
#	UTILS
#
# UTILS project
#
set(INC_UTILS
	.
)

set(INC_SYS_UTILS
	utils/file_ops.h
	utils/ImageStream.h
)

set(SRC_UTILS
	utils/intern/file_ops.cpp
	utils/intern/ImageStream.cpp
	

)
include_directories(utils ${INC_SYS_CORE})

#if(STB_IMAGE)
#	include_directories(utils ${STB_IMAGE_INC})
#endif()


add_library(utils ${SRC_UTILS} ${INC_SYS_UTILS})
target_link_libraries(utils core)



#
#END UTILS
#####################################################################################




#
#	IMAGEPROC
#
# Image Processing project
#
set(INC_IMAGEPROC
	.
)
set(INC_SYS_IMAGEPROC
	imageproc/edge_detection.h
	imageproc/imageproc_gray.h
)
set(SRC_IMAGEPROC
	imageproc/intern/EdgeDetection.cpp
	imageproc/intern/ImageProc_Gray.cpp
)

include_directories(imageproc ${INC_CORE})
if(TESTS)
	add_library(imageproc ${SRC_IMAGEPROC} ${INC_SYS_IMAGEPROC})
else()
	add_executable(imageproc ${SRC_IMAGEPROC} ${INC_SYS_IMAGEPROC})
endif()
target_link_libraries(imageproc core)
target_link_libraries(imageproc utils)
#
#END IMAGEPROC
#####################################################################################


#
#	CLASSIFICATION
#
# CLASSIFICATION project
#
set(INC_CLASSIFICATION
	.
)

set(INC_SYS_CLASSIFICATION
	classification/image_classification.h
	classification/classification_image_utils.h
)

set(SRC_CLASSIFICATION
	classification/intern/image_classification.cpp
	classification/intern/classification_image_utils.cpp
)
include_directories(utils ${INC_CORE})

if(TESTS)
	add_library(classification ${SRC_CLASSIFICATION} ${INC_SYS_CLASSIFICATION})
else()
	add_executable(classification ${SRC_CLASSIFICATION} ${INC_SYS_CLASSIFICATION})
endif()
target_link_libraries(classification core)
target_link_libraries(classification utils)
#
#END CLASSIFICATION
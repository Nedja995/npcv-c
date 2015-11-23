
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
	#core/npstdlib/xprintf.h
	
	
)

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
add_executable(core ${SRC_CORE} ${INC_SYS_CORE})
#
#END CORE
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
	imageproc/intern/EdgeDetection.cpp
)
add_executable(imageproc ${SRC_IMAGEPROC} ${INC_SYS_IMAGEPROC})
#
#END IMAGEPROC
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
	utils/FileCSV.h
	utils/ImageStream.h
)

set(SRC_UTILS
	utils/intern/file_ops.cpp
	utils/intern/FileCSV.cpp
	utils/intern/ImageStream.cpp
	
)

add_executable(utils ${SRC_UTILS} ${INC_SYS_UTILS})
#
#END UTILS
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
)

set(SRC_CLASSIFICATION
	classification/intern/image_classification.cpp
)

add_executable(classification ${SRC_CLASSIFICATION} ${INC_SYS_CLASSIFICATION})
#
#END CLASSIFICATION
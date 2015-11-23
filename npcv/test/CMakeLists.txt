#
#	TEST IMAGE READ WRITE
#
# Image Processing project
#
set(INC_TESTIMAGERW
	.
)
set(INC_SYS_TESTIMAGERW
	imageproc/edge_detection.h
	imageproc/imageproc_gray.h
)
set(SRC_TESTIMAGERW
	imageproc/intern/EdgeDetection.cpp
	imageproc/intern/EdgeDetection.cpp
)
add_executable(imageproc ${SRC_TESTIMAGERW} ${INC_SYS_TESTIMAGERW})
#
#END IMAGEPROC
#####################################################################################
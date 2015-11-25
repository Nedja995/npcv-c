#
#	TEST IMAGE READ WRITE
#
# Image Processing project
#
set(INC_TESTS
	.
	../src
)
set(INC_SYS_TESTS
	DataTest.h
)
set(SRC_TESTS
	TestManager.cpp
)




add_executable(tests ${SRC_TESTS} ${INC_SYS_TESTS})

include_directories(../src)
#include_directories(tests ${INC_SYS_UTILS})
#include_directories(tests ${INC_SYS_CLASSIFICATION})
#include_directories(tests ${INC_SYS_IMAGEPROC})

target_link_libraries(tests core)
target_link_libraries(tests utils)
target_link_libraries(tests imageproc)
target_link_libraries(tests classification)
#
#END IMAGEPROC
#####################################################################################
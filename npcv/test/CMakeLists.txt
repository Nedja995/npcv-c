#
#	TEST IMAGE READ WRITE
#
# Image Processing project
#

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(TESTS_INC
	DataTest.h
)

set(TESTS_SRC
	TestManager.cpp
)


add_executable(tests ${TESTS_SRC} ${TESTS_INC})

include_directories(tests ${PROJECT_INCLUDE})

target_link_libraries(tests core)
target_link_libraries(tests utils)
target_link_libraries(tests imageproc)
target_link_libraries(tests classification)
#
#END IMAGEPROC
#####################################################################################
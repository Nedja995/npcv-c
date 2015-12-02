#
#	TEST IMAGE READ WRITE
#
# Image Processing project
#

#
# GTest
#

#if(GTEST)
set(GTEST_DIR ${CMAKE_SOURCE_DIR}/lib/gtest)
set(GTEST_INC ${GTEST_DIR}/include)
set(GTEST_LIBDIR ${GTEST_DIR}/win)

set(GTEST_LIBS gmock.dll gmock_main.dll)

#endif()

if(GTEST)
add_definitions(-DWITH_GTEST)
endif()

#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(TESTS_INC
	DataTest.h
)

set(TESTS_SRC
	TestManager.cpp
)

#include_directories(${gtest_SOURCE_DIR}/include)
include_directories(tests ${PROJECT_INCLUDE})
#if(GTEST)
include_directories(tests ${GTEST_INC})
	

#endif()




add_executable(tests ${TESTS_SRC} ${TESTS_INC})
TARGET_LINK_LIBRARIES(tests ${GTEST_DIR}/win/gmock.lib)
TARGET_LINK_LIBRARIES(tests ${GTEST_DIR}/win/gmock_main.lib)
#target_link_libraries(tests gtest_main)

target_link_libraries(tests core)
target_link_libraries(tests utils)
target_link_libraries(tests imageproc)
target_link_libraries(tests classification)
#
#END IMAGEPROC
#####################################################################################
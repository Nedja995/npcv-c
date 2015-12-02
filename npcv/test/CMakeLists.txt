#
#	(G)Test project
#
#


set(GTEST_DIR ${GTEST_ROOT}/googletest)
set(GTEST_INC ${GTEST_DIR}/include)
set(GTEST_LIBDIR ${CMAKE_SOURCE_DIR}/libs)

#set(GTEST_LIBS gmock.dll gmock_main.dll)

#endif()

#project include
#set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(TEST_INC
	
)

set(TEST_SRC
	gtest_main.cc
)

#include_directories(${gtest_SOURCE_DIR}/include)
#include_directories(tests ${PROJECT_INCLUDE})
include_directories(tests ${GTEST_INC})
	
add_executable(tests ${TEST_SRC} ${TEST_INC})
TARGET_LINK_LIBRARIES(tests ${GTEST_DIR}/win/gmock.lib)
TARGET_LINK_LIBRARIES(tests ${GTEST_DIR}/win/gmock_main.lib)
#target_link_libraries(tests gtest_main)

#
#END IMAGEPROC
#####################################################################################
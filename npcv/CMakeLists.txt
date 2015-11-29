
cmake_minimum_required (VERSION 2.8.11)
project (NPComputerVision)

option(STB_IMAGE "With stb image library" YES)

option(DEBUG_VLD "Only for Win" NO)
option(DEBUG_TRACE "Write trace file" YES)

#tests
option(TESTS "With tests project" YES)
option(TEST_CORE "With tests project" YES)
option(TEST_UTILS "With tests project" YES)
option(TEST_IMGPROC "With tests project" YES)
option(TEST_CLASSIFICATION "With tests project" YES)

option(MODULE_IMGPROC "With tests project" YES)
option(MODULE_CLASSIFICATION "With tests project" YES)

#if(MODULE_CLASSIFICATION)
	#preprocessor
#	add_definitions(-D_NP_WITH_CLASSIFICATION)
#endif()

#if(MODULE_IMGPROC)
	#preprocessor
#	add_definitions(-D_NP_WITH_IMGPROC)
#endif()

if(DEBUG_TRACE)
	#preprocessor
	add_definitions(-D_NP_DEBUG_TRACE)
endif()

if(DEBUG_VLD)
	#preprocessor
	add_definitions(-D_NP_DEBUG_VLD)
endif()

if(TEST_CORE)
	#preprocessor
	add_definitions(-D_NP_TEST_CORE)
endif()

if(TEST_UTILS)
	#preprocessor
	add_definitions(-D_NP_TEST_UTILS)
endif()

if(TEST_IMGPROC)
	#preprocessor
	add_definitions(-D_NP_TEST_IMGPROC)
endif()

if(TEST_CLASSIFICATION)
	#preprocessor
	add_definitions(-D_NP_TEST_CLASSIFICATION)
endif()

add_subdirectory(src)
add_subdirectory(test)

#
# DEFINED IN EVERY CMAKE FILE
#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

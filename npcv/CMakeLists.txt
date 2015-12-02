
cmake_minimum_required (VERSION 2.8.11)

project (NPComputerVision)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dev)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib/dev)

####################################
#
# OPTIONS
#

option(MODULE_IMGPROC "With tests project" YES)
option(MODULE_CLASSIFICATION "With tests project" YES)

option(STB_IMAGE "With stb image library" YES)

option(DEBUG_TRACE "Write trace file" YES)

option(DEBUG_WITH_VLD "Only for Win" NO)

option(EXAMPLES "With tests project" YES)

option(WITH_GTEST "With gtest project" NO)
option(PATHH PATH "dasdasd")
option(BUILD_GTEST "Builds the googletest subproject" OFF)
option(BUILD_GMOCK "Builds the googlemock subproject" ON) #Note that googlemock target already builds googletest
#
#
###############################################################


###########################################
# ADD DIRECTORIES
#
add_subdirectory(src)

if(EXAMPLES)
	add_subdirectory(examples)
endif()


###########################################
#
#
# PREPROCESSOR DEFINITIONS
#
#

#if(MODULE_CLASSIFICATION)
	#preprocessor
#	add_definitions(-D_NP_WITH_CLASSIFICATION)
#endif()

#if(MODULE_IMGPROC)
	#preprocessor
#	add_definitions(-D_NP_WITH_IMGPROC)
#endif()

#########################################
#
#  THIRD PART
#
#
#
# GTest
#
if(WITH_GTEST)
	add_subdirectory(test)
	set(GTEST_ROOT /thirdparty/googletest-master)
	#gtest cmake
	if(BUILD_GMOCK)
		add_subdirectory(${GTEST_ROOT}/googlemock)
	elseif(BUILD_GTEST)
		add_subdirectory(${GTEST_ROOT}/googletest)
	endif()
endif()
#
###########################################

#
################################################






#
# DEFINED IN EVERY CMAKE FILE
#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

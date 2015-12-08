
cmake_minimum_required (VERSION 2.8.11)

project (NPComputerVision)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/dev)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib/dev)

####################################
#
# OPTIONS
#
option(MODULE_IMGPROC "With image processing module" YES)
option(MODULE_CLASSIFICATION "With classification module" YES)

option(DEBUG_TRACE "Write all trace logs to default file" YES)
option(DEBUG_WITH_VLD "Visual Leak Detector for Windows" NO)

option(EXAMPLES "With examples project" YES)

# It is only way to load/write image for now
#option(WITH_STB_IMAGE "With stb image library " YES)
set(WITH_STB_IMAGE YES)

option(GTEST "Add GTest to project" YES)
option(GTEST_DOWNLOAD_GTEST_AND_GMOCK "Download GTest." YES)
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/test/gtest/gtest" CACHE PATH "If downloading is disable this will be used. The path to the GooglTest cloned repository.")
set(GTEST_GMOCK_DIR "${CMAKE_SOURCE_DIR}/test/gtest/gmock" CACHE PATH "If downloading is disable this will be used. The path to the GooglMock cloned repository.")
# This is understanding now
#option(BUILD_GTEST "Builds the googletest subproject" OFF)
#option(BUILD_GMOCK "Builds the googlemock subproject" ON) #Note that googlemock target already builds googletest

#
#
###############################################################


###########################################
# ADD DIRECTORIES
#

# Add projects
add_subdirectory(src)

# Add examples project
if(EXAMPLES)
	add_subdirectory(examples)
endif()

# Add GTest project
if(GTEST)
	add_subdirectory(test)
endif()
#
###########################################


#
# DEFINED IN EVERY CMAKE FILE
#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

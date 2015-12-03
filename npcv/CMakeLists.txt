
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


option(DEBUG_TRACE "Write trace file" YES)
if(MSVC)
	option(DEBUG_WITH_VLD "Only for Win" NO)
endif()

option(EXAMPLES "With tests project" YES)

# Iit is only way to load/write image for now
#option(WITH_STB_IMAGE "With stb image library " YES)
set(WITH_STB_IMAGE YES)
option(WITH_GTEST "With gtest project" NO)

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
if(WITH_GTEST)
	add_subdirectory(test)
endif()

#
###########################################


#
# DEFINED IN EVERY CMAKE FILE
#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

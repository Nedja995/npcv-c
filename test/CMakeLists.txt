#
#	(G)Test project
#
#


#project include
#set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(TEST_INC

)

set(TEST_SRC
	gtest_main.cc
)


#
# Download gtest and gmock packages
#
find_package(Threads REQUIRED)
add_executable(tests ${TEST_SRC} ${TEST_INC})
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

if(GTEST_DOWNLOAD_GTEST_AND_GMOCK)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
	gtest
	URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
	# Disable install step
	INSTALL_COMMAND ""
)

# Set gtest properties
ExternalProject_Get_Property(gtest source_dir binary_dir)
set_target_properties(tests PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
#    "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
)
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/include")

# Download and install GoogleMock
ExternalProject_Add(
	gmock
	URL https://googlemock.googlecode.com/files/gmock-1.7.0.zip
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gmock
	# Disable install step
	INSTALL_COMMAND ""
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gmock)

# Set gmock properties
ExternalProject_Get_Property(gmock source_dir binary_dir)
set_target_properties(libgmock PROPERTIES
	"IMPORTED_LOCATION" "${binary_dir}/libgmock.a"
	"IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
#    "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
)

else()
add_subdirectory(${GTEST_GMOCK_DIR})

include_directories(tests ${GTEST_DIR}/include)

endif()


# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/include")

#
# Include npcv headers
#
include_directories(tests ${CMAKE_SOURCE_DIR}/include)

#
# Include Gmock headers to project 'tests'
#
include_directories(tests ${CMAKE_CURRENT_BINARY_DIR}/gmock/src/gmock/include)

if(GTEST_DOWNLOAD_GTEST_AND_GMOCK)
#
# Link gmock to project 'tests'
#
if(MSVC)
TARGET_LINK_LIBRARIES(tests ${CMAKE_CURRENT_BINARY_DIR}/gmock/src/gmock-build/${CMAKE_CFG_INTDIR}/gmock.lib)
TARGET_LINK_LIBRARIES(tests ${CMAKE_CURRENT_BINARY_DIR}/gmock/src/gmock-build/${CMAKE_CFG_INTDIR}/gmock_main.lib)
else()
TARGET_LINK_LIBRARIES(tests libgmock)
#TARGET_LINK_LIBRARIES(tests ${CMAKE_CURRENT_BINARY_DIR}/gmock/src/gmock-build/libmock_main.a)
endif()

else()
if(MSVC)
target_link_libraries(tests ${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/gmock.lib)
else()
target_link_libraries(tests gmock)
endif()
endif()

#
#END IMAGEPROC
#####################################################################################

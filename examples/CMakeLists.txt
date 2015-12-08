#
#	EXAMPLES
#
#


#project include
set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

#examples datas root directory path
#input and otput datas
add_definitions(-DEXAMPLES_DATA_DIR=\"${CMAKE_SOURCE_DIR}/examples/datas/\")

set(EXAMPLES_INC
	ExamplesDatas.h
)

set(EXAMPLES_SRC
	ExamplesManager.cpp
)

include_directories(examples ${PROJECT_INCLUDE})

add_executable(examples ${EXAMPLES_SRC} ${EXAMPLES_INC})

target_link_libraries(examples core)
target_link_libraries(examples utils)
target_link_libraries(examples imageproc)
target_link_libraries(examples classification)

#
#END IMAGEPROC
#####################################################################################
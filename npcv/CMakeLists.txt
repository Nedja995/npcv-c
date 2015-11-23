
cmake_minimum_required (VERSION 2.8.11)
project (NPComputerVision)

option(STB_IMAGE "With stb image library" YES)



add_subdirectory(src)
#add_subdirectory(test)
#add_executable(core src/Image.cpp)
#add_subdirectory(src/imageproc)
#add_executable(image_processing src/imageproc/intern/EdgeDetection.cpp)
cmake_minimum_required(VERSION 3.16)

project(MP4Cropper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)

add_subdirectory(src)
add_subdirectory(mp4Crop)
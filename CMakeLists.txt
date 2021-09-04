cmake_minimum_required(VERSION 3.12)

project(mh-tool)

# find the opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(test)
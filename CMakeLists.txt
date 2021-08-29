cmake_minimum_required(VERSION 3.12)

project(mh-tool)

FILE(GLOB_RECURSE SCR scr/*.cpp src/*.h scr/*.hpp src/*.c src/*.cc)

# find the opencv
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(mh-tool ${SCR})

add_subdirectory(test)
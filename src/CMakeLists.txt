FILE(GLOB_RECURSE SCR *.cpp *.h *.hpp *.c *.cc)

#CMake Error at src/CMakeLists.txt:3 (add_executable):
#Cannot find source file:
#
#opencv_calib3d
#message("OpenCV_LIBS: ${OpenCV_LIBS}")
find_library(easybot REQUIRED)
add_executable(mh-tool ${SCR} ${OpenCV_LIBS} easybot)

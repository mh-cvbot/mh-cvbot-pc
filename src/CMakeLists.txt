FILE(GLOB_RECURSE SCR *.cpp *.h *.hpp *.c *.cc)

find_library(easybot REQUIRED)
add_executable(mh-tool ${SCR})
# looks like easybot didn't come with the include?
target_link_libraries(mh-tool ${OpenCV_LIBS} easybot)

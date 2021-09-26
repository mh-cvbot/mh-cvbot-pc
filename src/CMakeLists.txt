FILE(GLOB_RECURSE SCR *.cpp *.h *.hpp *.c *.cc)

add_executable(mh-tool ${SCR})
target_include_directories(mh-tool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# looks like easybot didn't come with the include?
target_link_libraries(mh-tool ${OpenCV_LIBS} easybot)

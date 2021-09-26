FILE(GLOB_RECURSE SCR *.cpp *.h *.hpp *.c *.cc)

add_executable(mh-tool ${SCR})
target_include_directories(mh-tool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(mh-tool ${OpenCV_LIBS} easybot Qt5::Widgets)


FILE(GLOB_RECURSE SRC_LIB *.cpp *.h *.hpp *.c *.cc)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

message(${SRC_LIB})
list(FILTER SRC_LIB EXCLUDE REGEX ".*main.cc$")

add_library(mh-tool-lib ${SRC_LIB})
# public and interface will not work
target_include_directories(mh-tool-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(mh-tool-lib ${OpenCV_LIBS} easybot Qt5::Widgets)


add_executable(mh-tool ${SRC_LIB} main.cc)
target_link_libraries(mh-tool mh-tool-lib)

SET_TARGET_PROPERTIES(mh-tool PROPERTIES LINK_FLAGS  "/MANIFESTUAC:\"level='requireAdministrator'\"")
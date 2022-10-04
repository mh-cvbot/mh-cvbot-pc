FILE(GLOB_RECURSE SRC_LIB *.cpp *.h
        *.hpp *.c *.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_definitions(-DNOMINMAX)

list(FILTER SRC_LIB EXCLUDE REGEX ".*main.cc$")
list(FILTER SRC_LIB EXCLUDE REGEX ".*pch.cc$")

find_package(Tesseract REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

add_library(${PROJECT_NAME}-lib ${SRC_LIB})
target_include_directories(${PROJECT_NAME}-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(${PROJECT_NAME}-lib
        easybot
        pictool_lib
        ${OpenCV_LIBS}
        Qt5::Widgets Boost::filesystem
        libtesseract)

add_executable(${PROJECT_NAME} ${SRC_LIB} main.cc)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS  "/MANIFESTUAC:\"level='requireAdministrator'\"")
FILE(GLOB_RECURSE SRC_LIB *.cpp *.h *.hpp *.c *.cc ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.h ${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(FILTER SRC_LIB EXCLUDE REGEX ".*main.cc$")


# why you not complain?
# Still I can't find the tesseract name.
find_package(Tesseract REQUIRED)

add_library(mh-tool-lib ${SRC_LIB})

if(MSVC)
    get_target_property(_srcs mh-tool-lib  SOURCES)

    if(NOT CMAKE_GENERATOR MATCHES "Visual Studio .*")
        set_property(SOURCE pch.cc APPEND PROPERTY OBJECT_OUTPUTS "${CMAKE_CURRENT_BINARY_DIR}/pch.pch")
        set_property(SOURCE ${_srcs} APPEND PROPERTY OBJECT_DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/pch.pch")
    endif()

    set_source_files_properties(pch.cc PROPERTIES COMPILE_FLAGS "/Ycpch.h")
    target_sources(mh-tool-lib PRIVATE pch.cc)
    target_compile_options(mh-tool-lib PRIVATE /Yupch.h /FIpch.h /Zm200)
else()
    target_compile_options(mh-tool-lib PRIVATE -include "${CMAKE_CURRENT_SOURCE_DIR}/include/pch.h")
endif()

# public and interface will not work
target_include_directories(mh-tool-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

find_package(Boost REQUIRED COMPONENTS system filesystem)
target_link_libraries(mh-tool-lib
        ${OpenCV_LIBS} easybot Qt5::Widgets Boost::filesystem
        libtesseract)


add_executable(mh-tool ${SRC_LIB} main.cc)
target_link_libraries(mh-tool mh-tool-lib)

SET_TARGET_PROPERTIES(mh-tool PROPERTIES LINK_FLAGS  "/MANIFESTUAC:\"level='requireAdministrator'\"")

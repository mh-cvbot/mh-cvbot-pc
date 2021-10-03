FILE(GLOB_RECURSE SRC_LIB *.cpp *.h *.hpp *.c *.cc)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

list(FILTER SRC_LIB EXCLUDE REGEX ".*main.cc$")

add_library(mh-tool-lib ${SRC_LIB})
# public and interface will not work
target_include_directories(mh-tool-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if (NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR Please set the vcpkg_root env)
else()
    if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    endif()
endif()

# set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system filesystem REQUIRED)
#find_package(Boost REQUIRED COMPONENTS filesystem)
#target_link_libraries(mh-tool-lib PRIVATE Boost::boost Boost::filesystem)
target_link_libraries(mh-tool-lib ${OpenCV_LIBS} easybot Qt5::Widgets Boost::filesystem)


add_executable(mh-tool ${SRC_LIB} main.cc)
target_link_libraries(mh-tool mh-tool-lib)

SET_TARGET_PROPERTIES(mh-tool PROPERTIES LINK_FLAGS  "/MANIFESTUAC:\"level='requireAdministrator'\"")
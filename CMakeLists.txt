cmake_minimum_required(VERSION 3.12)


# why you can configure?
# can I show all the env?
if (NOT DEFINED ENV{VCPKG_ROOT})
    message(FATAL_ERROR "Please set the vcpkg_root env")
else()
    if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    endif()
endif()

project(mh-cvbot)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find the opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include(cmake/create_external_easybot.cmake)
add_subdirectory(external/easybot)

add_subdirectory(src)
add_subdirectory(test)
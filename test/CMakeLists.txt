# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

#do the copy
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

function(addTest name needRoot)
    add_executable(
            ${name}
            ${name}.cc
    )

    target_link_libraries(
            ${name}
            gtest_main
    )

    gtest_discover_tests(${name})
    target_link_libraries(${name} ${OpenCV_LIBS} mh-tool-lib)
    target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
    if(${needRoot})
        SET_TARGET_PROPERTIES(${name} PROPERTIES LINK_FLAGS  "/MANIFESTUAC:\"level='requireAdministrator'\"")
    endif()
endfunction()


addTest(hello_test FALSE)
addTest(test_mm FALSE)
addTest(test_cv FALSE)


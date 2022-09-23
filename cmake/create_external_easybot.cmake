# how to check file exist.

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/easybot")
else()
    execute_process(
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
            COMMAND "mkdir external"
            COMMAND "ln -s ../easybot external/easybot"
    )
endif()
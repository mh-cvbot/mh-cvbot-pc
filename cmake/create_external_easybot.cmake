# how to check file exist.

message("${CMAKE_CURRENT_SOURCE_DIR}")
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../external/easybot")
else()
    message("Begin create a symbol link to to easybot")
    execute_process(
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
            COMMAND "mkdir external"
            COMMAND "ln -s ../easybot external/easybot"
    )
endif()
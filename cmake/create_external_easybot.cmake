# how to check file exist.

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/easybot")
    message("link external easybot")
    execute_process(
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMAND "mkdir external"
#            COMMAND "ln -s ../easybot external/easybot"
            # this need admin privage
            COMMAND "new-item -ItemType SymbolicLink -Path external/easybot -Target ${CMAKE_CURRENT_SOURCE_DIR}../../easybot"
    )
endif()
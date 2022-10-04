# how to check file exist.

# create external
function(create_external name)
#    message("name: ${name}")
    if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external")
        execute_process(
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                COMMAND "mkdir external"
        )
    endif()

    if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/${name}")
        execute_process(
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                #            COMMAND "ln -s ../easybot external/easybot"
                # this need admin privage
                COMMAND "new-item -ItemType SymbolicLink -Path external/{name} -Target ${CMAKE_CURRENT_SOURCE_DIR}../../{name}"
        )
    endif()
endfunction()


create_external(easybot)
create_external(pictool)
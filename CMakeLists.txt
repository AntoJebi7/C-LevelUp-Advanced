cmake_minimum_required(VERSION 3.28)
project(cprograms C)

set(CMAKE_C_STANDARD 11)

# Find all .c files in the project directory (including subdirectories)
file(GLOB_RECURSE C_FILES "${CMAKE_SOURCE_DIR}/*.c")

# Create a separate executable for each .c file
foreach(C_FILE ${C_FILES})
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)

    # Skip files that are not supposed to be directly compiled (optional)
    if(EXEC_NAME STREQUAL "CMakeLists")
        continue()
    endif()

    # Add each .c file as a separate executable
    add_executable(${EXEC_NAME} ${C_FILE}
            Linked_Lists/Linked_list_ex1.c
    )

endforeach()

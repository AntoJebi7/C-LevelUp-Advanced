cmake_minimum_required(VERSION 3.28)
project(cprograms C)

set(CMAKE_C_STANDARD 11)

# Find all .c files in the project directory
file(GLOB_RECURSE C_FILES "${CMAKE_SOURCE_DIR}/*.c")

# Create a separate executable for each .c file
foreach(C_FILE ${C_FILES})
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)
    add_executable(${EXEC_NAME} ${C_FILE})
endforeach()



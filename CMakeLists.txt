cmake_minimum_required(VERSION 3.18)

project(noe)

add_subdirectory(External/glfw)

add_library(noe STATIC
    External/glad/src/glad.c
)

set_target_properties(noe PROPERTIES PUBLIC_HEADER include/noe.h)

target_include_directories(noe
    PUBLIC External/glad/include
    PUBLIC External/glfw/include
    PUBLIC include
)

target_link_directories(noe
    PRIVATE External/glad/include
    PRIVATE External/glfw/include
    PRIVATE include
)

target_link_libraries(noe
    glfw
)
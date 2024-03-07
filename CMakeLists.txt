cmake_minimum_required(VERSION 3.18)

project(noe)

set(HEADER_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Noe.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Window.h
)

set( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl, -undefined" )

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/External/glfw)

add_library(noe SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/External/glad/src/glad.c
    ${CMAKE_CURRENT_SOURCE_DIR}/External/glfw/src/libglfw3.a
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Window.cpp
    ${HEADER_FILES}
)

set_target_properties(noe PROPERTIES PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/noe.h)

target_include_directories(noe
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/External/glad/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/External/glfw/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_directories(noe
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/External/glad/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/External/glfw/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(noe
    glfw
)
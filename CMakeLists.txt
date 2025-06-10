cmake_minimum_required(VERSION 3.16)
project(bezier-curve-3d LANGUAGES CXX)
set(LIB_NAME bezier-curve-3d)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SRC_FILES src/*.cpp)

add_library(${LIB_NAME} STATIC
    ${SRC_FILES}
)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

target_include_directories(${LIB_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PARENT_DIR}/ext/eigen
)

set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
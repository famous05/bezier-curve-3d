cmake_minimum_required(VERSION 3.15)
project(bezier-curve-3d LANGUAGES CXX)
set(LIB_NAME bezier-curve-3d)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3)
find_package(GTest)

# Conan Integration
include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)
include(${CMAKE_BINARY_DIR}/generators/conandeps_legacy.cmake)

# Include folders
include_directories(${CMAKE_SOURCE_DIR}/include)

# Main Library
file(GLOB LIB_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(${LIB_NAME} ${LIB_SOURCES})
target_link_libraries(${LIB_NAME} PUBLIC Eigen3::Eigen)

# Unit Tests
#enable_testing()
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS test/unit/*.cpp)
add_executable(${LIB_NAME}_Test ${TEST_SOURCES})
target_link_libraries(${LIB_NAME}_Test PRIVATE ${LIB_NAME} GTest::gtest_main)
add_test(NAME bezier-curve-3d-test COMMAND ${LIB_NAME}_Test)

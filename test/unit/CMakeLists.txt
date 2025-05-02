
cmake_minimum_required(VERSION 3.16)
project(BezierLiteLibrary LANGUAGES CXX)

find_package(GTest REQUIRED)
message(STATUS "GoogleTest found at: ${GTest_DIR}")

# Include directories
include_directories(
    ${GTest_DIR}
    "${CMAKE_BINARY_DIR}/source/include"
    )


add_executable(Point3DTests Point3D_UT.cpp main.cpp)

target_link_libraries(Point3DTests
    PRIVATE
        BezierLite
        GTest::GTest
        GTest::Main
)

enable_testing()
add_test(NAME Point3DTests COMMAND Point3DTests)
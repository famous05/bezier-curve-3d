
cmake_minimum_required(VERSION 3.16)
project(BezierLiteLibrary LANGUAGES CXX)

# Include Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/v1.10.0.zip # Use a specific version
    # The following line prevents conflicts with system-installed gtest
    PREFIX ${CMAKE_PROJECT_NAME}
)
# Disable its main() function
set(gtest_disable_main ON)
FetchContent_MakeAvailable(googletest)


# find_package(GTest REQUIRED)
# message(STATUS "GoogleTest found at: ${GTest_DIR}")

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
add_test(NAME Point3DTests COMMAND ./Point3DTests)
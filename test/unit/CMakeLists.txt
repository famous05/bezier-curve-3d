list(APPEND CMAKE_PREFIX_PATH "$ENV{GOOGLETEST_INSTALL_PATH}")

find_package(GTest REQUIRED)
message(STATUS "GoogleTest found at: ${GTest_DIR}")

# Include directories
include_directories(
    ${GTest_DIR}
    "${CMAKE_BINARY_DIR}/source/include"
    )

message(cpp = ${CMAKE_PREFIX_PATH})
message(genv=  "$ENV{GOOGLETEST_INSTALL_PATH}")

add_executable(Point3DTests Point3D_UT.cpp main.cpp)

target_link_libraries(Point3DTests PRIVATE BezierLite GTest::gtest_main)

enable_testing()
add_test(NAME Point3DTests COMMAND Point3DTests)



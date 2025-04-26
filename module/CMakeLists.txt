cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

project(BezierLite.Point3D LANGUAGES CXX)

# Set the library name in a variable
set(LIB_NAME BezierLite.Point3D)

# Tell CMake to use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable modules support
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API ON)

# Add ability to fecth uninstalled content (e.g. libs)
include(FetchContent)

# Try to find Eigen first
find_package(Eigen3 QUIET)

# If not found, fetch Eigen
if(NOT Eigen3_FOUND)
    message(STATUS "Eigen3 not found, fetching via FetchContent...")

    FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG        3.4.0
    )

    FetchContent_MakeAvailable(eigen)
endif()


# # Create the static library
add_library(${LIB_NAME} STATIC)

# # Tell CMake this is a C++20 module
target_sources(${LIB_NAME}
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            Point3D.ixx
            Utils.ixx
)


# Link Eigen to our library
target_link_libraries(${LIB_NAME}
    PUBLIC Eigen3::Eigen
)

# If using Eigen
target_include_directories(${LIB_NAME} PUBLIC ${eigen3_SOURCE_DIR})

# Require C++20 features
target_compile_features(${LIB_NAME} PUBLIC  cxx_std_20)

set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)


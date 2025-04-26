cmake_minimum_required(VERSION 3.26)

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

# Create the static library
add_library(${LIB_NAME} STATIC)

# Set properties for modules
set_target_properties(${LIB_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Add the module interface source
target_sources(${LIB_NAME}
    PRIVATE
        Point3D.ixx
        Utils.ixx
)

# Link Eigen to our library
target_link_libraries(${LIB_NAME}
    PUBLIC Eigen3::Eigen
)

# Require C++20 features
target_compile_features(${LIB_NAME} PRIVATE cxx_std_20)

# (Optional) Better organization in IDEs like Visual Studio
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES Point3D.ixx)

set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)


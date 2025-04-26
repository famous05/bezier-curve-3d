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

# Create the static library
add_library(${LIB_NAME} STATIC)

# Add the module interface source
target_sources(${LIB_NAME}
    PRIVATE
        Point3D.ixx
)

# Require C++20 features
target_compile_features(${LIB_NAME} PRIVATE cxx_std_20)

# (Optional) Better organization in IDEs like Visual Studio
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES Point3D.ixx)

set_target_properties(${LIB_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)


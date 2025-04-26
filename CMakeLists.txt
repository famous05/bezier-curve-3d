# Root CMakeLists.txt

cmake_minimum_required(VERSION 3.29)
project(BezierLite LANGUAGES CXX)

# 🧠 Enable module dependency scanning
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    eigen3
    URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
)
FetchContent_MakeAvailable(eigen3)

# 📦 Add module
add_subdirectory(module)
add_subdirectory(app/src)


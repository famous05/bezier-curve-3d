# Root CMakeLists.txt

cmake_minimum_required(VERSION 3.29)
project(BezierLiteProject LANGUAGES CXX)

# 🧠 Enable module dependency scanning
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 📦 Add module
add_subdirectory(source)


cmake_minimum_required(VERSION 3.16)
project(BezierLiteLibrary LANGUAGES CXX)

# Create executable for the app
set(NAME SampleApp)

add_executable(${NAME} app.cpp)

# Link the static library to the app
target_link_libraries(${NAME} PRIVATE BezierLite)

target_compile_features(${NAME} PUBLIC cxx_std_17)

target_include_directories(${NAME} PRIVATE ${eigen3_SOURCE_DIR})

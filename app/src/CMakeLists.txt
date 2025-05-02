cmake_minimum_required(VERSION 3.16)
project(BezierLiteLibrary LANGUAGES CXX)

# Create executable for the app
set(APP_NAME SampleApp)

add_executable(${APP_NAME} app.cpp)

# Link the static library to the app
target_link_libraries(${APP_NAME} PRIVATE BezierLite)

target_compile_features(${APP_NAME} PUBLIC cxx_std_17)

target_include_directories(${APP_NAME} PRIVATE ${eigen3_SOURCE_DIR})

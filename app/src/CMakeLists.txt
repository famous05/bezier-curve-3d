# Create executable for the app
set(APP_NAME SampleApp)

add_executable(${APP_NAME} app.cpp)

# Link the static library to the app
target_link_libraries(${APP_NAME} PRIVATE BezierLite.Point3D)

target_compile_features(${APP_NAME} PUBLIC cxx_std_20)

# If your Point3D module uses Eigen, the app will need it too
target_include_directories(${APP_NAME} PRIVATE ${eigen3_SOURCE_DIR})

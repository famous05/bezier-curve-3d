#!/bin/bash

# Default build type
BUILD_TYPE="Debug"
BUILD_DIR="build"
EXT_LIB_DIR="ext"

# Boolean values
FALSE=0
TRUE=1

CLEAN=$FALSE

# Check the first argument
if [[ "$1" == "-r" ]]; then
    BUILD_TYPE="Release"
elif [[ "$1" == "-d" ]]; then
    BUILD_TYPE="Debug"
elif [[ "$1" == "-c" ]]; then
    CLEAN=$TRUE
elif [[ -n "$1" ]]; then
    echo "Unknown option: $1"
    echo "Usage: $0 [-r | -d | -c]"
    exit 1
fi

if [[ "$2" == "-c" ]]; then
    CLEAN=$TRUE
fi

if [ ! -d $EXT_LIB_DIR ]; then
    mkdir -p "$EXT_LIB_DIR"
fi

# Clone Eigen
if [ -d "ext/eigen/.git" ]; then
    echo "Eigen already cloned."
else
    cd $EXT_LIB_DIR
    echo "Eigen not found. Cloning..."
    git clone https://gitlab.com/libeigen/eigen.git
    cd ..
fi

# # Clone, build and install googletest
# if [ -d "ext/googletest/.git" ]; then
#     echo "Googletest already cloned."
# else
#     cd $EXT_LIB_DIR
#     echo "Googletest not found. Cloning..."
#     git clone https://github.com/google/googletest.git
#     cd googletest
#     mkdir build && cd build
#     cmake .. -DCMAKE_INSTALL_PREFIX=/your/install/path
#     cmake --build . --target install
# fi

if [ $CLEAN -eq $TRUE ]; then
    echo "Cleaning out previous build files in  $BUILD_DIR"
    # Check if the script is running in PowerShell
    if $([ -n "$PSVersionTable" ] && echo "$PSVersionTable.PSVersion" | grep -q "^[0-9]\+\.[0-9]\+\.[0-9]\+" ); then
        # PowerShell
        echo "Running in PowerShell"
        powershell -Command "Remove-Item -Recurse -Force '$BUILD_DIR'"
    else
        # Bash (Unix-like environments such as Git Bash, WSL, etc.)
        echo "Running in Bash"
        rm -rf "$BUILD_DIR"
    fi
fi

echo "Building in $BUILD_TYPE mode..."

# Create and enter the build directory
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# Configure with CMake
cmake ..

# Build
cmake --build . --config $BUILD_TYPE

# Go back to project root
cd ..

# Keep terminal open
read -p "Press ENTER to exit..."


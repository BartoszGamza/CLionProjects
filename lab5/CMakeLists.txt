cmake_minimum_required(VERSION 3.7)
project(lab5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/lab5
        cmake-build-debug/lab5.cbp
        cmake-build-debug/lab5.exe
        cmake-build-debug/Makefile
        CMakeLists.txt
        main.cpp)

add_executable(lab5 ${SOURCE_FILES})
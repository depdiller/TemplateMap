cmake_minimum_required(VERSION 3.20)
project(Google_test)

set(CMAKE_CXX_STANDARD 23)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_library(MAP_LIB libmapTemplate.a
        PATHS ../cmake-build-debug/BinarySearchTree/)

link_libraries(gtest_main ${MAP_LIB})
include_directories(../BinarySearchTree/src)

add_executable(mapTest googleTestMap.cpp)
cmake_minimum_required(VERSION 3.21)
project(mapTemplate)

set(CMAKE_CXX_STANDARD 20)

add_executable(mapTemplate main.cpp BinarySearchTree/src/BinarySearchTree.cpp BinarySearchTree/src/BinarySearchTree.h BinarySearchTree/src/Node.h BinarySearchTree/src/Node.cpp)

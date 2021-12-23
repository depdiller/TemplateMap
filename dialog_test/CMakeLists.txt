find_library(MAP_LIB libmapTemplate.a
        PATHS ../cmake-build-debug/BinarySearchTree/)

add_executable(dialog main.cpp)

target_link_libraries(dialog PRIVATE ${MAP_LIB})
target_include_directories(dialog PRIVATE ../BinarySearchTree/src)
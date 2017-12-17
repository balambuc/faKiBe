set(CMAKE_CXX_STANDARD 11)

add_library(src STATIC
        Tree.h Tree.cpp)

target_include_directories(src PUBLIC headers)
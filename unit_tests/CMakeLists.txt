cmake_minimum_required(VERSION 3.2)
project(unit_tests)

set(CMAKE_CXX_STANDARD 11)

add_executable(unit_tests
        catch.hpp
        main.cpp
        )

target_link_libraries(unit_tests src)

add_test(NAME unit_tests_faKiBe COMMAND unit_tests)



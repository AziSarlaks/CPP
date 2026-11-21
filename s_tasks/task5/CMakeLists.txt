cmake_minimum_required(VERSION 3.14)

project(OOP_05 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_subdirectory(my_lib)

add_executable(exec_trg main.cpp)

target_link_libraries(exec_trg PUBLIC mylib)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

cmake_minimum_required(VERSION 3.10)

project(task5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(library)

add_executable(task5 main.cpp)
target_link_libraries(task5 PRIVATE hypotenuse_library)

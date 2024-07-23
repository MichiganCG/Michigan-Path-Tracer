cmake_minimum_required(VERSION 3.26)
project(mpt LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

add_executable(mpt src/main.cpp)
add_subdirectory(src)
add_subdirectory(ext)

set_property(TARGET mpt PROPERTY CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
target_include_directories(mpt PUBLIC include)

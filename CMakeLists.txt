cmake_minimum_required(VERSION 3.15)
project(Cryptography)

set(CMAKE_CXX_STANDARD 14)
include_directories(src)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest-master)


cmake_minimum_required (VERSION 2.6)
project (Neurone)

set(CMAKE_CXX_FLAGS "-O3 -std=c++11")
add_executable (Neurone Constants.hpp Neurone.cpp Connection.cpp main.cpp)

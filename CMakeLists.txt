cmake_minimum_required(VERSION 3.7)
project(data_structures_hashing)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp hasher.cpp hasher.h dictionary.cpp dictionary.h)
add_executable(data_structures_hashing ${SOURCE_FILES})
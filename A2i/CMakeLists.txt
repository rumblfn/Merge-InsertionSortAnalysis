cmake_minimum_required(VERSION 3.29)
project(A2i)

set(CMAKE_CXX_STANDARD 23)

add_executable(A2i main.cpp
        utils/ArrayGenerator.cpp
        utils/ArrayGenerator.h
        utils/SortTester.h
        utils/SortTester.cpp
        utils/MergeSort.h
        utils/MergeSort.cpp)

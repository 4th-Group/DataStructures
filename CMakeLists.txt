cmake_minimum_required(VERSION 3.20)
project(DataStruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStruct arrQueue.h ForwardListOnArray.h DequeOnArray.h main.cpp StackOnArray.h ListOnArray.h)

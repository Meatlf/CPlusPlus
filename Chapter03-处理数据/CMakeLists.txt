# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(Chapter03 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

add_executable(divide divide.cpp)
add_executable(modulus modulus.cpp)
add_executable(floatnum floatnum.cpp)
add_executable(fltadd fltadd.cpp)
add_executable(exercise4 exercise4.cpp)
add_executable(exercise5 exercise5.cpp)

# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(Chapter05 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

add_executable(equal2 equal2_统计0的个数.cpp)
add_executable(formore formore.cpp)
add_executable(exercise01 exercise01.cpp)
add_executable(exercise02 exercise02.cpp)

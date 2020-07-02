# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(chapter02 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

add_executable(myfirst myfirst.cpp)
add_executable(convert convert.cpp)
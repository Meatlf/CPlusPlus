# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(Chapter05 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

add_executable(compstr1 compstr1.cpp)
add_executable(formore formore.cpp)
add_executable(textin1 textin1.cpp)
add_executable(nested nested.cpp)
add_executable(equal2 equal2_统计0的个数.cpp)
add_executable(exercise01 exercise01.cpp)
add_executable(exercise02 exercise02.cpp)
add_executable(exercise03 exercise03.cpp)
add_executable(exercise04 exercise04.cpp)
add_executable(exercise05 exercise05.cpp)
add_executable(exercise06 exercise06.cpp)
add_executable(exercise07 exercise07.cpp)
add_executable(exercise08 exercise08.cpp)
add_executable(exercise09 exercise09.cpp)
add_executable(exercise10 exercise10.cpp)

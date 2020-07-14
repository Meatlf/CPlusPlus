# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(chapter04 LANGUAGES CXX)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

add_executable(strings strings.cpp)
add_executable(use_new use_new.cpp)
add_executable(instr1 instr1.cpp)
add_executable(instr2 instr2.cpp)
add_executable(strtype1 strtype1.cpp)
add_executable(strtype4 strtype4.cpp)
add_executable(mixtypes mixtypes.cpp)
add_executable(exercise01 exercise01.cpp)
add_executable(exercise02 exercise02.cpp)
add_executable(exercise03 exercise03.cpp)
add_executable(exercise04 exercise04.cpp)
add_executable(exercise05 exercise05.cpp)
add_executable(exercise07 exercise07.cpp)
add_executable(exercise08 exercise08.cpp)
add_executable(exercise09 exercise09.cpp)
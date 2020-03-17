# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(class LANGUAGES CXX)

add_executable(stack stacker.cpp stack.cpp stack.h)
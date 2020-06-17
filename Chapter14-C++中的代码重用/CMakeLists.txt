cmake_minimum_required(VERSION 3.0.0)
project(chapter14 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/example1")

add_executable(example1_test ./use_stuc.cpp)

# 添加子目录
add_subdirectory(example1)

# 添加project0库
target_link_libraries(example1_test example1)

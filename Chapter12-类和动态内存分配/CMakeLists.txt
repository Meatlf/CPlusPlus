cmake_minimum_required(VERSION 3.0.0)
project(Chapter12 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/Project0")

add_executable(test_project0 ./vegnews.cpp)

# 添加子目录
add_subdirectory(Project0)

# 添加project0库
target_link_libraries(test_project0 Project0)

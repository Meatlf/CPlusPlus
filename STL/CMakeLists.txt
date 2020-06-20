cmake_minimum_required(VERSION 3.0.0)
project(STL VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
# include_directories("${PROJECT_SOURCE_DIR}/example1")

add_executable(pair_test ./pair_test.cpp)
# add_executable(example2_test ./pairs.cpp)
# add_executable(exercise1_test ./exercise1_test.cpp)

# 添加子目录
# add_subdirectory(example1)

# 添加project0库
# target_link_libraries(example1_test example1)

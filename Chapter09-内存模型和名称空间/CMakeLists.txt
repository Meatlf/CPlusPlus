cmake_minimum_required(VERSION 3.0.0)
project(Chapter10 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/exercise1")
include_directories("${PROJECT_SOURCE_DIR}/exercise4")

add_executable(external ./external.cpp support.cpp)
add_executable(golf_test ./golf_test.cpp)
add_executable(test_exercise2 ./exercise2.cpp)
add_executable(exercise4_test ./exercise4_test.cpp)

# 添加子目录
add_subdirectory(exercise1)
add_subdirectory(exercise4)

# 添加库
target_link_libraries(golf_test golf)
target_link_libraries(exercise4_test sales)

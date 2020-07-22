cmake_minimum_required(VERSION 3.0.0)
project(Chapter10 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/Exercise1")
include_directories("${PROJECT_SOURCE_DIR}/Exercise4")

add_executable(external ./external.cpp support.cpp)
add_executable(file ./file1.cpp file2.cpp)
add_executable(twofile ./twofile1.cpp twofile2.cpp)
add_executable(static ./static.cpp)
add_executable(newplace ./newplace.cpp)
add_executable(exercise1 ./exercise1.cpp)
add_executable(exercise2 ./exercise2.cpp)
add_executable(exercise3 ./exercise3.cpp)
add_executable(exercise4 ./exercise4.cpp)

# 添加子目录
add_subdirectory(Exercise1)
add_subdirectory(Exercise4)

# 添加库
target_link_libraries(exercise1 golf)
target_link_libraries(exercise4 sales)

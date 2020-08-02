# set minimum cmake version
cmake_minimum_required(VERSION 3.0.0)

# project name and language
project(Chapter15 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/example1")
include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(use_tv ./use_tv.cpp)
add_executable(nested ./nested.cpp)
add_executable(exercise1_test ./exercise1.cpp)
add_executable(error1 ./error1.cpp)
add_executable(error3 ./error3.cpp)
add_executable(error4 ./error4.cpp)
add_executable(error5 ./error5.cpp)
add_executable(12_1 ./12_1.cpp)
add_executable(12_2 ./12_2.cpp)
add_executable(12_3 ./12_3.cpp)

# 添加子目录
add_subdirectory(example1)
add_subdirectory(exercise1)

# 添加project0库
target_link_libraries(use_tv example1)
target_link_libraries(exercise1_test exercise1)
cmake_minimum_required(VERSION 3.0.0)
project(chapter11 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/example1")
include_directories("${PROJECT_SOURCE_DIR}/exercise2")
include_directories("${PROJECT_SOURCE_DIR}/exercise4")
include_directories("${PROJECT_SOURCE_DIR}/exercise5")
include_directories("${PROJECT_SOURCE_DIR}/exercise7")

add_executable(example1_test randwalk.cpp)
add_executable(exercise1_test exercise1_test.cpp)
add_executable(exercise2_test exercise2_test.cpp)
add_executable(exercise3_test exercise3_test.cpp)
add_executable(exercise4_test exercise4_test.cpp)
add_executable(exercise5_test exercise5_test.cpp)
add_executable(exercise7_test exercise7_test.cpp)

# 添加子目录
add_subdirectory(example1)
add_subdirectory(exercise2)
add_subdirectory(exercise4)
add_subdirectory(exercise5)
add_subdirectory(exercise7)

# 添加库
target_link_libraries(example1_test example1)
target_link_libraries(exercise1_test example1)
target_link_libraries(exercise2_test exercise2)
target_link_libraries(exercise3_test example1)
target_link_libraries(exercise4_test exercise4)
target_link_libraries(exercise5_test exercise5)
target_link_libraries(exercise7_test exercise7)

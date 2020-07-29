cmake_minimum_required(VERSION 3.0.0)
project(Chapter14 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/example1")
include_directories("${PROJECT_SOURCE_DIR}/example1_2")
include_directories("${PROJECT_SOURCE_DIR}/exercise1")
include_directories("${PROJECT_SOURCE_DIR}/exercise2")

add_executable(example1_test ./use_stuc.cpp)
add_executable(example1_2_test ./example1_2_test.cpp)
add_executable(example2_test ./pairs.cpp)
add_executable(exercise1_test ./exercise1_test.cpp)
add_executable(exercise2_test ./exercise2_test.cpp)
add_executable(example4_2_test ./example4_2_test.cpp)
add_executable(workmi ./workmi.cpp workermi.cpp)
add_executable(worktest ./worktest.cpp worker0.cpp)
add_executable(tempmemb ./tempmemb.cpp)
add_executable(tempparm ./tempparm.cpp)
add_executable(frnd2tmp ./frnd2tmp.cpp)

# 添加子目录
add_subdirectory(example1)
add_subdirectory(example1_2)
add_subdirectory(exercise1)
add_subdirectory(exercise2)

# 添加project0库
target_link_libraries(example1_test example1)
target_link_libraries(example1_2_test example1_2)
target_link_libraries(exercise1_test exercise1)
target_link_libraries(exercise2_test exercise2)

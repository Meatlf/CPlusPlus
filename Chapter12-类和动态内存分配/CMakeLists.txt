cmake_minimum_required(VERSION 3.0.0)
project(Chapter12 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/Project0")
include_directories("${PROJECT_SOURCE_DIR}/Project1")
include_directories("${PROJECT_SOURCE_DIR}/example4")
include_directories("${PROJECT_SOURCE_DIR}/exercise1")
include_directories("${PROJECT_SOURCE_DIR}/exercise2")
include_directories("${PROJECT_SOURCE_DIR}/exercise3")
include_directories("${PROJECT_SOURCE_DIR}/exercise4")

add_executable(test_project0 ./vegnews.cpp)
add_executable(test_project1 ./sayings2.cpp)
add_executable(example4_test ./bank.cpp)
add_executable(exercise1_test exercise1_test.cpp)
add_executable(exercise2_test exercise2_test.cpp)
add_executable(exercise3_test exercise3_test.cpp)
add_executable(exercise4_test exercise4_test.cpp)

# 添加子目录
add_subdirectory(Project0)
add_subdirectory(Project1)
add_subdirectory(example4)
add_subdirectory(exercise1)
add_subdirectory(exercise2)
add_subdirectory(exercise3)
add_subdirectory(exercise4)

# 添加库
target_link_libraries(test_project0 Project0)
target_link_libraries(test_project1 Project1)
target_link_libraries(example4_test example4)
target_link_libraries(exercise1_test exercise1)
target_link_libraries(exercise2_test exercise2)
target_link_libraries(exercise3_test exercise3)
target_link_libraries(exercise4_test exercise4)

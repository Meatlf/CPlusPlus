cmake_minimum_required(VERSION 3.0.0)
project(Chapter10 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/exercise1")
include_directories("${PROJECT_SOURCE_DIR}/exercise2")
include_directories("${PROJECT_SOURCE_DIR}/exercise3")
include_directories("${PROJECT_SOURCE_DIR}/exercise4")
include_directories("${PROJECT_SOURCE_DIR}/exercise6")
include_directories("${PROJECT_SOURCE_DIR}/exercise7")

add_executable(usestok2 ./usestok2.cpp stock20.cpp)
add_executable(test_exercise1 ./bank_count_test.cpp)
add_executable(test_exercise2 ./person_test.cpp)
add_executable(exercise3_test ./exercise3_test.cpp)
add_executable(exercise4_test ./exercise4_test.cpp)
add_executable(exercise6_test ./exercise6_test.cpp)
add_executable(exercise7_test ./exercise7_test.cpp)
add_executable(4_1 ./4_1.cpp)
add_executable(4_1_2 ./4_1_2.cpp)

# 添加子目录
add_subdirectory(exercise1)
add_subdirectory(exercise2)
add_subdirectory(exercise3)
add_subdirectory(exercise4)
add_subdirectory(exercise6)
add_subdirectory(exercise7)

# 添加库
target_link_libraries(test_exercise1 exercise1)
target_link_libraries(test_exercise2 exercise2)
target_link_libraries(exercise3_test exercise3)
target_link_libraries(exercise4_test exercise4)
target_link_libraries(exercise6_test exercise6)
target_link_libraries(exercise7_test exercise7)

cmake_minimum_required(VERSION 3.0.0)
project(chapter11 VERSION 0.1.0)

include(CTest)
enable_testing()

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}")
# include_directories("${PROJECT_SOURCE_DIR}/exercise2")
# include_directories("${PROJECT_SOURCE_DIR}/exercise3")
# include_directories("${PROJECT_SOURCE_DIR}/exercise4")
# include_directories("${PROJECT_SOURCE_DIR}/exercise6")

add_executable(exercise1_test exercise1_test.cpp vect.cpp)
# add_executable(test_exercise2 ./person_test.cpp)
# add_executable(test_exercise3 ./golf_test.cpp)
# add_executable(exercise4_test ./exercise4_test.cpp)
# add_executable(exercise6_test ./exercise6_test.cpp)

# 添加子目录
# add_subdirectory(exercise1)
# add_subdirectory(exercise2)
# add_subdirectory(exercise3)
# add_subdirectory(exercise4)
# add_subdirectory(exercise6)

# 添加库
# target_link_libraries(exercise1_test exercise1)
# target_link_libraries(test_exercise2 exercise2)
# target_link_libraries(test_exercise3 exercise3)
# target_link_libraries(exercise4_test exercise4)
# target_link_libraries(exercise6_test exercise6)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

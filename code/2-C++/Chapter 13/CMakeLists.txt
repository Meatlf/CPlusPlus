cmake_minimum_required(VERSION 3.0.0)
project(chapter13 VERSION 0.1.0)

include(CTest)
enable_testing()

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
include_directories("${PROJECT_SOURCE_DIR}/project0")
include_directories("${PROJECT_SOURCE_DIR}/project1")

add_executable(test_project0 ./usett0.cpp)
add_executable(test_project1 ./usett1.cpp)

# 添加子目录
add_subdirectory(project0)
add_subdirectory(project1)

# 添加project0库
target_link_libraries(test_project0 project0)
target_link_libraries(test_project1 project1)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

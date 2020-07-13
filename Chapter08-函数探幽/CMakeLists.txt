cmake_minimum_required(VERSION 3.0.0)
project(Chapter07 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
# include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(secref ./secref.cpp)
add_executable(strtref ./strtref.cpp)
add_executable(strc_ref ./strc_ref.cpp)
add_executable(tempover ./tempover.cpp)
add_executable(exercise1 ./exercise1.cpp)

# 添加子目录
# add_subdirectory(exercise1)

# 添加库
# target_link_libraries(golf_test golf)

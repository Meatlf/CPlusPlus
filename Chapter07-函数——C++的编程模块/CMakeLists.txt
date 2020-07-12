cmake_minimum_required(VERSION 3.0.0)
project(Chapter07 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
# include_directories("${PROJECT_SOURCE_DIR}/exercise1")

add_executable(arrfun1 ./arrfun1.cpp)
add_executable(arrfun2 ./arrfun2.cpp)
add_executable(fun_ptr ./fun_ptr.cpp)
add_executable(arfupt ./arfupt.cpp)
add_executable(recur ./recur.cpp)
add_executable(ruler ./ruler.cpp)
add_executable(exercise01 ./exercise01.cpp)
add_executable(exercise02 ./exercise02.cpp)
add_executable(exercise03 ./exercise03.cpp)
add_executable(exercise04 ./exercise04.cpp)
add_executable(exercise05 ./exercise05.cpp)
add_executable(exercise06 ./exercise06.cpp)

# 添加子目录
# add_subdirectory(exercise1)

# 添加库
# target_link_libraries(golf_test golf)

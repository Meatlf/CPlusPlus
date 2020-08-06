# set minimum cmake version
cmake_minimum_required(VERSION 3.0.0)

# project name and language
project(Chapter16 VERSION 0.1.0)

#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")

# 添加头文件路径
# include_directories("${PROJECT_SOURCE_DIR}/example1")

add_executable(str1 ./str1.cpp)
add_executable(strfile ./strfile.cpp)
add_executable(hangman ./hangman.cpp)
add_executable(str2 ./str2.cpp)
add_executable(smrtptrs ./smrtptrs.cpp)
add_executable(fowl ./fowl.cpp)
add_executable(vect1 ./vect1.cpp)
add_executable(vect2 ./vect2.cpp)
add_executable(vect3 ./vect3.cpp)
add_executable(exa10_1 ./exa10_1.cpp)

# 添加子目录
# add_subdirectory(example1)

# 添加project0库
# target_link_libraries(example1_test example1)
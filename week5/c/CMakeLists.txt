# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(cs4c)
add_executable(${PROJECT_NAME} src/cs4c.cpp src/list2.cpp)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-O3")
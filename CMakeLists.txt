cmake_minimum_required(VERSION 3.1)

project(data_structure_by_cpp)

add_subdirectory(LinkList)
add_subdirectory(tests)
add_subdirectory(List)

add_executable(main.cpp main)

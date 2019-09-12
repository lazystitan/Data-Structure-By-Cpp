cmake_minimum_required(VERSION 3.1)

project(data_structure_by_cpp)

add_compile_options(-std=c++14)

add_subdirectory(Tests)
add_subdirectory(DataStructure)
add_subdirectory(Thread)
add_subdirectory(STL)
add_subdirectory(ACM)

add_executable(main main.cpp)

cmake_minimum_required(VERSION 3.1)

project(data_structure_by_cpp)

add_compile_options(-std=c++14)

add_subdirectory(LinkList)
add_subdirectory(Tests)
add_subdirectory(List)
add_subdirectory(Vector)
add_subdirectory(Stack)
add_subdirectory(Queue)
add_subdirectory(BinaryTree)
add_subdirectory(Graph)
add_subdirectory(Thread)

add_executable(main main.cpp)

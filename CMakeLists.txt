cmake_minimum_required(VERSION 3.23)
project(my_binary_search_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_binary_search_tree main.cpp src/my_binary_search_tree.cpp lib/my_binary_search_tree.h lib/header.h lib/node.h)

cmake_minimum_required(VERSION 3.20.1)
project(my_binary_search_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp src/bst.cpp lib/bst.h lib/header.h lib/node.h lib/tree_iterator.h lib/user_functions.h src/user_functions.cpp src/rb_tree.cpp lib/rb_tree.h lib/rb_tree_iterator.h)


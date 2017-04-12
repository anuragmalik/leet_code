cmake_minimum_required(VERSION 3.7)
project(leet_code)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES valid_parentheses.cpp duplicate3.cpp cont_subarraysum.cpp valid_bst.cpp largest_num.cpp can_i_win.cpp rotate_list.cpp)
add_executable(leet_code ${SOURCE_FILES})
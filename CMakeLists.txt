cmake_minimum_required(VERSION 3.21)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode main.cpp)

add_executable(017.multiSearch 树专题/017.multiSearch.cpp 动态规划/uniquePaths.cpp)
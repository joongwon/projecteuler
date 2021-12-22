cmake_minimum_required(VERSION 3.20)
project(ProjectEuler)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(problems/001/)
add_subdirectory(problems/002/)
add_executable(problem_template utils/problem_template.cpp)
add_subdirectory(problems/003/)
add_subdirectory(problems/004/)

add_subdirectory(problems/005/)

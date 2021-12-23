cmake_minimum_required(VERSION 3.20)
project(ProjectEuler)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
endif ()

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(problems/001/)
add_subdirectory(problems/002/)
add_executable(problem_template utils/problem_template.cpp)
add_subdirectory(problems/003/)
add_subdirectory(problems/004/)

add_subdirectory(problems/005/)

add_subdirectory(problems/006/)

add_subdirectory(problems/007/)

add_subdirectory(problems/008/)

add_subdirectory(problems/009/)

add_subdirectory(problems/010/)

add_subdirectory(problems/011/)

add_subdirectory(problems/012/)

add_subdirectory(problems/013/)

add_subdirectory(problems/014/)

add_subdirectory(problems/015/)

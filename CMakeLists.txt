cmake_minimum_required(VERSION 2.8.4)
project(emli-competitive-programming)

add_executable(testrunner testrunner/main.cpp)
file(GLOB TASKS "tasks/*.cpp")
file(GLOB_RECURSE HEADERS "library/*.hpp" )

ADD_DEFINITIONS(-std=c++17)

add_executable(test ${TASKS} ${HEADERS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -fsanitize=address -Wno-sign-compare")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMY_DEBUG")
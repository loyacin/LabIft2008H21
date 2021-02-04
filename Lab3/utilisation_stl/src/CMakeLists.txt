project(lab3)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

add_executable(iterating iterating.cc)
add_executable(iterable_class iterable_class.cc)
add_executable(maps maps.cc)
add_executable(stacks_queues stacks_queues.cc)
add_executable(time_comparison time_comparison.cc)

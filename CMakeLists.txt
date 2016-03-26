cmake_minimum_required(VERSION 3.4)
project(ue01)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c stack.h stack.c)
add_executable(ue01 ${SOURCE_FILES})

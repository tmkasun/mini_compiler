cmake_minimum_required(VERSION 3.1)
project(c_parser)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES Simple_parser.c)
add_executable(c_parser ${SOURCE_FILES} Simple_parser.c)
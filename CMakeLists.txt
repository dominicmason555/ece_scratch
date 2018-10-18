cmake_minimum_required(VERSION 3.12)
project(parse_test)

set(CMAKE_CXX_STANDARD 17)

include_directories(${parse_test_SOURCE_DIR}/include)
link_directories(${parse_test_SOURCE_DIR}/src)

add_executable(parse_test src/main.cpp)
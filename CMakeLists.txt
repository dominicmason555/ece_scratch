cmake_minimum_required(VERSION 3.12)
project(ece_scratch)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)

add_executable(ece_scratch
        include/Model.h
        include/Vec3.h
        include/Cell.h
        include/Result.h
        src/main.cpp
        src/Model.cpp
        src/Vec3.cpp
        src/Cell.cpp
        )

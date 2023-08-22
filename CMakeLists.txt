cmake_minimum_required(VERSION 3.25)
project(JET)
set(CMAKE_CXX_FLAGS -static-libgcc)
set(CMAKE_CXX_FLAGS -static-libstdc++)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_CXX_STANDARD 17)
set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

add_executable(JET main.cpp Core/Thread.c Core/Thread.h Core/Def.h Core/Stack.c Core/Stack.h)

cmake_minimum_required(VERSION 3.19)
project(YCompress)

set(CMAKE_CXX_STANDARD 14)

add_executable(YCompress main.cpp char_buffer.cpp char_buffer.h yjq_compressor.cpp yjq_compressor.h)
cmake_minimum_required(VERSION 3.19)
project(YCompress)

set(CMAKE_CXX_STANDARD 14)

add_executable(YCompress main.cpp compressor/char_buffer.cpp header/char_buffer.h compressor/compressor.cpp compressor/flow_compressor.cpp header/compressor.h)
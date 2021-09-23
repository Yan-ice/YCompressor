cmake_minimum_required(VERSION 3.19)
project(YCompress)

set(CMAKE_CXX_STANDARD 14)
add_executable(YCompress main.cpp lz77/char_buffer.cpp header/char_buffer.h lz77/compressor.cpp lz77/flow_compressor.cpp lz77/flow_compressor2.cpp delta/delta_compressor.cpp header/compressor.h)
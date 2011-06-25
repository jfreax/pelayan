project(pelayan)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lz") 

include_directories(./include ./extern/zlib-1.2.5/)
add_subdirectory(src)

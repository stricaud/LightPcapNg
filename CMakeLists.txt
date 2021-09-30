cmake_minimum_required (VERSION 2.6)
project (light_pcapng C)

include_directories(AFTER ${light_pcapng_SOURCE_DIR}/include)

add_subdirectory(src)

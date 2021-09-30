cmake_minimum_required (VERSION 3.4)
project (light_pcapng)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
message(FATAL_ERROR "CMake generation is not allowed within the source directory!
Remove the CMakeCache.txt file and try again from another folder, e.g.:

   rm CMakeCache.txt
   mkdir build
   cd build
   cmake ..
")
endif()

include_directories(AFTER ${light_pcapng_SOURCE_DIR}/include)

find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11)

add_subdirectory(src)

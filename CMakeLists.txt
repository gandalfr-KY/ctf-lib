cmake_minimum_required(VERSION 3.20)
project(GandalfrCTF VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR})

add_library(GandalfrCTF STATIC
    dummy.cpp
    crypt/ROT.hpp
    standard.hpp
    types.hpp
)

set_target_properties(GandalfrCTF PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

add_executable(main playground/main.cpp)
target_link_libraries(main PRIVATE GandalfrCTF)

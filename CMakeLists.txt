cmake_minimum_required(VERSION 3.27)
project(IslandFactory)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(dependencies/EngineBase)
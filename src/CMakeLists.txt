cmake_minimum_required(VERSION 3.29)
project(IslandFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(IslandFactory
        main.cpp
        IslandFactory.cpp
        IslandFactory.h
)


target_link_libraries(IslandFactory EngineBase)
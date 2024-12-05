cmake_minimum_required(VERSION 3.27)
project(IslandFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(IslandFactory
        main.cpp
        IslandFactory.cpp
        IslandFactory.h
        Island.cpp
        Island.h
        IslandController.cpp
        IslandController.h
)


target_link_libraries(IslandFactory EngineBase)
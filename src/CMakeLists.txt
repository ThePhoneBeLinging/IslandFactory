cmake_minimum_required(VERSION 3.27)
project(IslandFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(IslandFactory
        main.cpp
        IslandFactory.cpp
        Controllers/GameController.cpp
        Objects/Player.cpp
        Controllers/GameObjectController.cpp
)


target_link_libraries(IslandFactory EngineBase)
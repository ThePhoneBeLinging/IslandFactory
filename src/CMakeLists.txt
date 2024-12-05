cmake_minimum_required(VERSION 3.27)
project(IslandFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(IslandFactory
        main.cpp
        IslandFactory.cpp
        IslandFactory.h
        GameController.cpp
        GameController.h
        Objects/Player.cpp
        Objects/Player.h
        TextureList.h
        Objects/GameObjectController.cpp
        Objects/GameObjectController.h
)


target_link_libraries(IslandFactory EngineBase)
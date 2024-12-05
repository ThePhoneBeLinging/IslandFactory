cmake_minimum_required(VERSION 3.27)
project(IslandFactory)

set(CMAKE_CXX_STANDARD 20)

add_executable(IslandFactory
        main.cpp
        IslandFactory.cpp
        Controllers/GameController.cpp
        Objects/Player.cpp
        Controllers/GameObjectController.cpp
        Controllers/GameBoard.cpp
        Objects/Tiles/Tile.cpp
        Objects/Tiles/GrassTile.cpp
)


target_link_libraries(IslandFactory EngineBase)

target_include_directories(IslandFactory PRIVATE Controllers)
target_include_directories(IslandFactory PRIVATE Textures)
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
        Objects/Tiles/WaterTile.cpp
        Objects/Tiles/WaterTile.h
        Controllers/HoverController.cpp
        Controllers/HoverController.h
        Objects/PlaceAbles/PlaceAble.cpp
        Objects/PlaceAbles/PlaceAble.h
        Objects/PlaceAbles/CoalPlaceAble.cpp
        Objects/PlaceAbles/CoalPlaceAble.h
        Objects/Tiles/CoalTile.cpp
        Objects/Tiles/CoalTile.h
        Controllers/InventoryController.cpp
        Controllers/InventoryController.h
        Textures/ZValues.h
)


target_link_libraries(IslandFactory EngineBase)

target_include_directories(IslandFactory PRIVATE Controllers)
target_include_directories(IslandFactory PRIVATE Objects)
target_include_directories(IslandFactory PRIVATE Textures)
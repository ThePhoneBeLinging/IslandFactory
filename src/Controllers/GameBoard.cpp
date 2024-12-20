//
// Created by eal on 12/5/24.
//

#include <iostream>
#include "GameBoard.h"


#include "../Objects/Tiles/GrassTile.h"
#include "EngineBase/EngineBase.h"
#include "Tiles/CoalTile.h"
#include "Tiles/WaterTile.h"

GameBoard::GameBoard(std::shared_ptr<EngineBase>& engineBase) : engineBase_(engineBase)
{
    int x = 0;
    for (int i = 0; i < 150; i++)
    {
        int y = 0;
        tileMatrix_.emplace_back();
        for (int j = 0; j < 150; j++)
        {
            if (i < 15 && j < 15)
            {
                tileMatrix_[i].emplace_back(std::make_shared<GrassTile>());
            }
            else if (i == 15 || j == 15 || i == 16 || j == 16 || i == 17 || j == 17)
            {
                tileMatrix_[i].emplace_back(std::make_shared<GrassTile>());
            }
            else
            {
                tileMatrix_[i].emplace_back(std::make_shared<WaterTile>());
            }
            tileMatrix_[i][j]->setPosition(x,y);
            engineBase_->registerDrawAble(tileMatrix_[i][j]);
            y += Tile::TILESIZE;
        }
        x += Tile::TILESIZE;
    }
}

void GameBoard::handlePlayModeClicks(const std::pair<int, int>& mousePosition)
{
    auto offset = engineBase_->getSceneController()->getCurrentDrawAbleController()->getCurrentUpdateOffset();
    int transformedX = (mousePosition.first + static_cast<int>(offset.first * -1)) / Tile::TILESIZE;
    int transformedY = (mousePosition.second + static_cast<int>(offset.second * -1)) / Tile::TILESIZE;

    std::cout << "Tile pressed: " << transformedX << ", " << transformedY << std::endl;
    tileMatrix_[transformedX][transformedY]->onClick();
}

void GameBoard::handleBuildModeClicks(const std::pair<int, int>& mousePosition, std::shared_ptr<PlaceAble>& placeAble)
{
    auto offset = engineBase_->getSceneController()->getCurrentDrawAbleController()->getCurrentUpdateOffset();
    int transformedX = (mousePosition.first + static_cast<int>(offset.first * -1)) / Tile::TILESIZE;
    int transformedY = (mousePosition.second + static_cast<int>(offset.second * -1)) / Tile::TILESIZE;

    if (tileMatrix_[transformedX][transformedY]->getTextureLocation() == placeAble->getTileDrawAble()->getTextureLocation())
    {
        return;
    }
    tileMatrix_[transformedX][transformedY] = std::make_shared<CoalTile>();
    tileMatrix_[transformedX][transformedY]->setPosition(transformedX * Tile::TILESIZE, transformedY * Tile::TILESIZE);
    engineBase_->registerDrawAble(tileMatrix_[transformedX][transformedY]);
}

int GameBoard::getGridSideLength()
{
    return static_cast<int>(tileMatrix_.size());
}

std::shared_ptr<Tile>& GameBoard::getTile(int firstIndex, int secondIndex)
{
    return tileMatrix_[firstIndex][secondIndex];
}

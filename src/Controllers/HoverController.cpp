//
// Created by eal on 12/19/24.
//

#include "HoverController.h"

#include <iostream>

void HoverController::handleHovering(const std::pair<int, int>& mousePos, const std::pair<double,double>& currentOffset , std::shared_ptr<PlaceAble>& placeAble)
{
    if (placeAble == nullptr)
    {
        return;
    }
    // TODO Take currentOffset into account

    int mousePosXWithOffset = mousePos.first - static_cast<int>(currentOffset.first) % 50;
    int mPosX = mousePosXWithOffset - mousePosXWithOffset % Tile::TILESIZE;
    int modX = mPosX + static_cast<int>(currentOffset.first) % Tile::TILESIZE;


    int mousePosYWithOffset = mousePos.second - static_cast<int>(currentOffset.second) % 50;
    int mPosY = mousePosYWithOffset - mousePosYWithOffset % Tile::TILESIZE;
    int modY = mPosY + static_cast<int>(currentOffset.second) % Tile::TILESIZE;

    std::cout << mousePos.first << " " << mousePos.second << std::endl;

    placeAble->getTileDrawAble()->setPosition(modX,modY);
}
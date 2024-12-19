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
    int modX = mousePos.first - (mousePos.first % Tile::TILESIZE);
    int modY = mousePos.second - (mousePos.second % Tile::TILESIZE);

    placeAble->getTileDrawAble()->setPosition(modX,modY);
}

//
// Created by eal on 12/19/24.
//

#include "HoverController.h"

#include <iostream>

void HoverController::handleHovering(std::pair<int, int>& mousePos, std::shared_ptr<PlaceAble>& placeAble)
{
    int modX = mousePos.first - (mousePos.first % Tile::TILESIZE);
    int modY = mousePos.second - (mousePos.second % Tile::TILESIZE);

    placeAble->getTileDrawAble()->setPosition(modX,modY);
}

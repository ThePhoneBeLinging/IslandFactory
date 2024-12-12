//
// Created by eal on 12/5/24.
//

#include "Tile.h"

Tile::Tile()
{
    setWidth(TILESIZE);
    setHeight(TILESIZE);
}

void Tile::onClick()
{
    // DO NOTHING
}

bool Tile::isWalkAble()
{
    return true;
}

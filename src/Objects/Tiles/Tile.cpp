//
// Created by eal on 12/5/24.
//

#include "Tile.h"

#include "ZValues.h"

Tile::Tile()
{
    setSize(TILESIZE,TILESIZE);
    setZ(ZValues::TILEZ);
}

void Tile::onClick()
{
    // DO NOTHING
}

bool Tile::isWalkAble()
{
    return true;
}

//
// Created by eal on 12/19/24.
//

#ifndef PLACEABLE_H
#define PLACEABLE_H
#include <EngineBase/DrawAble.h>
#include <Tiles/Tile.h>


class PlaceAble
{
public:
    explicit PlaceAble(const std::shared_ptr<Tile>& tileDrawAble);
    std::shared_ptr<Tile>& getTileDrawAble();
protected:
    // TODO extend to allow for an interface, for selecting between 9 different placement tools.
    std::shared_ptr<Tile> tileDrawAble_;
};



#endif //PLACEABLE_H

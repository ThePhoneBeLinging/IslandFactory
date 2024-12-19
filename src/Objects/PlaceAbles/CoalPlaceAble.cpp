//
// Created by eal on 12/19/24.
//

#include "CoalPlaceAble.h"

#include "Tiles/CoalTile.h"

CoalPlaceAble::CoalPlaceAble() : PlaceAble(std::make_shared<CoalTile>())
{
}

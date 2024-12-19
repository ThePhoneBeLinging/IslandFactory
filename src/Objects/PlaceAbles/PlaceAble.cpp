//
// Created by eal on 12/19/24.
//

#include "PlaceAble.h"

#include <utility>

PlaceAble::PlaceAble(std::shared_ptr<Tile> tileDrawAble) : tileDrawAble_(std::move(tileDrawAble))
{
}

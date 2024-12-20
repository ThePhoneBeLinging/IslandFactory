//
// Created by eal on 12/19/24.
//

#include "PlaceAble.h"

#include <utility>

#include "ZValues.h"

PlaceAble::PlaceAble(const std::shared_ptr<Tile>& tileDrawAble) : tileDrawAble_(tileDrawAble)
{
    tileDrawAble_->setPositionIsAffectedByOffset(false);
    tileDrawAble->setZ(ZValues::PLACEABLEZ);
}

std::shared_ptr<Tile>& PlaceAble::getTileDrawAble()
{
    return tileDrawAble_;
}

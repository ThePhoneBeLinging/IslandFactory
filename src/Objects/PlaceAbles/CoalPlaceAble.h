//
// Created by eal on 12/19/24.
//

#ifndef COALPLACEABLE_H
#define COALPLACEABLE_H
#include "PlaceAble.h"


class CoalPlaceAble : public PlaceAble
{
public:
    CoalPlaceAble();
    std::shared_ptr<Tile> getTileByValue() override;
private:
};



#endif //COALPLACEABLE_H

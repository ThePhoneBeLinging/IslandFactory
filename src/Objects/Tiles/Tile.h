//
// Created by eal on 12/5/24.
//

#ifndef TILE_H
#define TILE_H

#include <EngineBase/DrawAble.h>

class Tile : public DrawAble
{
public:
    Tile();

    virtual void onClick();

    virtual bool isWalkAble();

    static inline const int TILESIZE = 50;
};


#endif //TILE_H

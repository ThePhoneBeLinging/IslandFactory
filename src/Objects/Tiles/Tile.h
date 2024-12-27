//
// Created by eal on 12/5/24.
//

#ifndef TILE_H
#define TILE_H

#include <EngineBase/DrawAble.h>
#include <EngineBase/EngineBase.h>

class Tile : public DrawAble
{
public:
    Tile();

    virtual void onClick();

    virtual bool isWalkAble();

    static inline const int TILESIZE = 50;

    void setEngineBase(const std::shared_ptr<EngineBase>& engineBase)
    {
        enginebase_ = engineBase;
    }
protected:
    std::weak_ptr<EngineBase> enginebase_;
};


#endif //TILE_H

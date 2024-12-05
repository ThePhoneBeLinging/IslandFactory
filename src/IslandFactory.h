//
// Created by eal on 12/5/24.
//

#ifndef IslandFactory_H
#define IslandFactory_H
#include "EngineBase/EngineBase.h"


class IslandFactory
{
public:
    IslandFactory();
    void start();
private:
    std::shared_ptr<EngineBase> engineBase_;
    std::shared_ptr<DrawAble> draw_able_;
    void draw_island();
};



#endif //IslandFactory_H

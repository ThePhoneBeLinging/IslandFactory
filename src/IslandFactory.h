//
// Created by eal on 12/5/24.
//

#ifndef IslandFactory_H
#define IslandFactory_H
#include "Controllers/GameController.h"
#include "EngineBase/EngineBase.h"


class IslandFactory
{
public:
    explicit IslandFactory(std::shared_ptr<EngineBase>& engineBase);

private:
    void update(double deltaTime);

    std::shared_ptr<EngineBase>& engineBase_;
    std::shared_ptr<GameController> gameController_;
};


#endif //IslandFactory_H

//
// Created by eal on 12/5/24.
//

#include "IslandFactory.h"
#include "Controllers/GameController.h"

IslandFactory::IslandFactory(std::shared_ptr<EngineBase>& engineBase)
    : engineBase_(engineBase), gameController_(std::make_shared<GameController>(engineBase_))
{
    auto lambdaUpdate = [this](double deltaTime)
    {
        gameController_->update(deltaTime);
    };
    engineBase_->registerUpdateFunction(lambdaUpdate);
}

void IslandFactory::update(const double deltaTime)
{
    gameController_->update(deltaTime);
}

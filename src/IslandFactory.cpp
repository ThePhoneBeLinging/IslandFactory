//
// Created by eal on 12/5/24.
//

#include "IslandFactory.h"
#include "Controllers/GameController.h"

IslandFactory::IslandFactory()
    : engineBase_(std::make_shared<EngineBase>()), gameController_(std::make_shared<GameController>(engineBase_))
{
    auto lambdaUpdate = [this](double deltaTime)
    {
        gameController_->update(deltaTime);
    };
    engineBase_->registerUpdateFunction(lambdaUpdate);
    engineBase_->launch();
}

void IslandFactory::update(const double deltaTime)
{
    gameController_->update(deltaTime);
}

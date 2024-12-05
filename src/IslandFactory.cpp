//
// Created by eal on 12/5/24.
//

#include "IslandFactory.h"
#include "Controllers/GameController.h"

void IslandFactory::launch()
{
    engineBase_ = std::make_shared<EngineBase>();
    gameController_ = std::make_shared<GameController>(engineBase_);
    engineBase_->registerUpdateFunction(&update);
    engineBase_->launch();
}

void IslandFactory::update(const double deltaTime)
{
    gameController_->update(deltaTime);
}

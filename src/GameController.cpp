//
// Created by eal on 12/5/24.
//

#include "GameController.h"
#include <utility>

GameController::GameController(std::shared_ptr<EngineBase>& engineBase)
    : engineBase_(engineBase)
    , gameObjectController_(std::make_unique<GameObjectController>(engineBase))
{
}

void GameController::update(const double deltaTime)
{
    handleInput(deltaTime);
}

void GameController::handleInput(const double deltaTime)
{
    gameObjectController_->handleMovement(deltaTime);
}

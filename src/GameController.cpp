//
// Created by eal on 12/5/24.
//

#include "GameController.h"

#include <iostream>
#include <utility>

GameController::GameController(std::shared_ptr<EngineBase> engineBase) : player_(std::make_shared<Player>()), engineBase_(std::move(engineBase))
{
    engineBase_->registerDrawAble(player_);
}

void GameController::update(const double deltaTime)
{
    handleInput(deltaTime);
}

void GameController::handleInput(const double deltaTime)
{
    double deltaMovement = player_->getMovementSpeed() * deltaTime;
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_W))
    {
        player_->setY(player_->getY() - deltaMovement);
    }
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_S))
    {
        player_->setY(player_->getY() + deltaMovement);
    }
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_A))
    {
        player_->setX(player_->getX() - deltaMovement);
    }
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_D))
    {
        player_->setX(player_->getX() + deltaMovement);
    }
}

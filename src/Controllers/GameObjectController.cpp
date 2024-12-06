//
// Created by eal on 12/5/24.
//

#include "GameObjectController.h"

#include <thread>
#include <utility>

GameObjectController::GameObjectController(std::shared_ptr<EngineBase>& engineBase)
    : gameBoard_(std::make_shared<GameBoard>(engineBase)), engineBase_(engineBase), player_(std::make_shared<Player>())
{
    engineBase_->registerDrawAble(player_);
    auto size = engineBase_->getGraphicsLibrary()->getWindowSize();
    player_->moveToCenter(size);
}

void GameObjectController::handleMovement(const double deltaTime)
{
    //TODO Move all other objects
    const double deltaMovement = player_->getMovementSpeed() * deltaTime;
    double deltaX = 0;
    double deltaY = 0;

    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_W))
    {
        deltaY += deltaMovement;
    }
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_S))
    {
        deltaY -= deltaMovement;
    }
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_A))
    {
        deltaX += deltaMovement;
    }
    if (engineBase_->getGraphicsLibrary()->isKeyDown(ENGINEBASE_KEY_D))
    {
        deltaX -= deltaMovement;
    }
    gameBoard_->moveObjects(deltaX, deltaY);
}

//
// Created by eal on 12/5/24.
//

#include "GameObjectController.h"

#include <thread>
#include <utility>
#include <iostream>

GameObjectController::GameObjectController(std::shared_ptr<EngineBase>& engineBase)
        : lmbPressed_(false), gameBoard_(std::make_shared<GameBoard>(engineBase)), engineBase_(engineBase),
          player_(std::make_shared<Player>())
{
    engineBase_->registerDrawAble(player_);
}

void GameObjectController::handleMovement(const double deltaTime)
{
    auto size = engineBase_->getGraphicsLibrary()->getWindowSize();
    player_->moveToCenter(size);
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
    engineBase_->getSceneController()->getCurrentDrawAbleController()->updateOffset(deltaX, deltaY);
    auto currentOffset = engineBase_->getSceneController()->getCurrentDrawAbleController()->getCurrentUpdateOffset();
    if (currentOffset.first > 0)
    {
        currentOffset.first = 0;
    }
    if (currentOffset.second > 0)
    {
        currentOffset.second = 0;
    }
    int maxOffset = gameBoard_->getGridSideLength() * Tile::TILESIZE * -1;
    auto windowSize = engineBase_->getGraphicsLibrary()->getWindowSize();
    if (currentOffset.first < maxOffset + windowSize.first)
    {
        currentOffset.first = maxOffset + windowSize.first;
    }
    if (currentOffset.second < maxOffset + windowSize.second)
    {
        currentOffset.second = maxOffset + windowSize.second;
    }

    for (const auto& tile: player_->getCollisionTiles(currentOffset))
    {
        if (not gameBoard_->getTile(tile.first, tile.second)->isWalkAble())
        {
            // TODO Try to undo moves
            std::cout << "COLLISION" << std::endl;
        }
    }


    engineBase_->getSceneController()->getCurrentDrawAbleController()->setOffset(currentOffset.first,
                                                                                 currentOffset.second);

}

void GameObjectController::handleClicks()
{
    //TODO Handle clicks for HUD, not only for tiles
    if (not lmbPressed_ && engineBase_->getGraphicsLibrary()->isMouseButtonDown(ENGINEBASE_BUTTON_LEFT))
    {
        lmbPressed_ = true;
        auto mousePos = engineBase_->getGraphicsLibrary()->getMousePos();
        //TODO Handle clicks
        gameBoard_->handleClicks(mousePos);
    }

    if (lmbPressed_ && not engineBase_->getGraphicsLibrary()->isMouseButtonDown(ENGINEBASE_BUTTON_LEFT))
    {
        lmbPressed_ = false;
    }
}

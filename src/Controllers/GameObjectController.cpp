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

    this->handleCollisionWithTerrain(currentOffset);

    engineBase_->getSceneController()->getCurrentDrawAbleController()->setOffset(currentOffset.first,
                                                                                 currentOffset.second);

}

void GameObjectController::handleCollisionWithTerrain(std::pair<double, double>& currentOffset)
{
    // Check collision
    // If collision, reduce offsetX, try again until x = 0
    // If still collision, reset x, reduce offsetY, try again until y=0
    // If still collision, both should be 0.

    bool collisionDetected = true;

    bool xValuesChecked = false;
    bool yValuesChecked = false;
    std::pair<double, double> localOffset = {currentOffset.first, currentOffset.second};
    std::pair<double, double> doubleCollisionOffset = {0, 0};
    while (collisionDetected)
    {
        collisionDetected = false;
        for (const auto& tileCords: player_->getCollisionTiles(localOffset))
        {
            if (not gameBoard_->getTile(tileCords.first, tileCords.second)->isWalkAble())
            {
                collisionDetected = true;

                if (not xValuesChecked && localOffset.first != 0)
                {
                    if (localOffset.first > 1)
                    {
                        localOffset.first -= 1;
                    }
                    else if (localOffset.first < -1)
                    {
                        localOffset.first -= -1;
                    }
                    else
                    {
                        localOffset.first = 0;
                        xValuesChecked = true;
                    }
                    break;
                }

                if (not yValuesChecked && localOffset.second != 0)
                {
                    if (localOffset.second > 1)
                    {
                        localOffset.second -= 1;
                    }
                    else if (localOffset.second < -1)
                    {
                        localOffset.second -= -1;
                    }
                    else
                    {
                        localOffset.second = 0;
                        yValuesChecked = true;
                    }
                    break;
                }
            }
        }
        if (not(xValuesChecked && yValuesChecked))
        {
            if (xValuesChecked)
            {
                localOffset.first = currentOffset.first;
            }
            if (yValuesChecked)
            {
                localOffset.second = currentOffset.second;
            }
        }

    }
    currentOffset = localOffset;
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

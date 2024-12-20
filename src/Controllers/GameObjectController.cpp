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

    this->handleCollisionWithTerrain(currentOffset, deltaX, deltaY);

    engineBase_->getSceneController()->getCurrentDrawAbleController()->setOffset(currentOffset.first,
        currentOffset.second);
}

void
GameObjectController::handleCollisionWithTerrain(std::pair<double, double>& currentOffset, double deltaX, double deltaY)
{
    if (deltaX == 0 && deltaY == 0)
    {
        return;
    }
    const auto trueLocationsCollisionTiles = player_->getCollisionTiles(currentOffset);
    std::vector<std::pair<int, int>> tileCords;
    for (auto& val : trueLocationsCollisionTiles)
    {
        std::pair<int, int> tileVals;
        tileVals.first = val.first;
        tileVals.second = val.second;
        tileVals.first -= currentOffset.first;
        tileVals.second -= currentOffset.second;
        tileVals.first /= Tile::TILESIZE;
        tileVals.second /= Tile::TILESIZE;
        tileCords.push_back(tileVals);
    }
    if (not gameBoard_->getTile(tileCords[0].first, tileCords[0].second)->isWalkAble())
    {
        currentOffset.second += player_->getY() - trueLocationsCollisionTiles[0].second - 1;
    }
    if (not gameBoard_->getTile(tileCords[1].first, tileCords[1].second)->isWalkAble())
    {
        currentOffset.second += trueLocationsCollisionTiles[1].second - (player_->getY() + player_->getHeight() - 1);
    }
    if (not gameBoard_->getTile(tileCords[2].first, tileCords[2].second)->isWalkAble())
    {
        currentOffset.first += player_->getX() - trueLocationsCollisionTiles[2].first - 1;
    }
    if (not gameBoard_->getTile(tileCords[3].first, tileCords[3].second)->isWalkAble())
    {
        currentOffset.first += trueLocationsCollisionTiles[3].first - (player_->getX() + player_->getWidth() - 1);
    }
}

void GameObjectController::handlePlayModeClicks(const std::pair<int, int>& mousePos)
{
    if (not lmbPressed_ && engineBase_->getGraphicsLibrary()->isMouseButtonDown(ENGINEBASE_BUTTON_LEFT))
    {
        lmbPressed_ = true;
        gameBoard_->handlePlayModeClicks(mousePos);
    }

    if (lmbPressed_ && not engineBase_->getGraphicsLibrary()->isMouseButtonDown(ENGINEBASE_BUTTON_LEFT))
    {
        lmbPressed_ = false;
    }
}

void GameObjectController::handleBuildModeClicks(const std::pair<int, int>& mousePos,
    std::shared_ptr<PlaceAble>& placeAble)
{
    if (engineBase_->getGraphicsLibrary()->isMouseButtonDown(ENGINEBASE_BUTTON_LEFT))
    {
        gameBoard_->handleBuildModeClicks(mousePos, placeAble);
    }
}

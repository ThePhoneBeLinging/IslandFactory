//
// Created by eal on 12/5/24.
//

#ifndef GAMEOBJECTCONTROLLER_H
#define GAMEOBJECTCONTROLLER_H

#include <GameBoard.h>
#include <memory>
#include <vector>

#include "Player.h"
#include "EngineBase/EngineBase.h"


class GameObjectController
{
public:
    explicit GameObjectController(std::shared_ptr<EngineBase>& engineBase);

    void handleMovement(double deltaTime);

    void handleCollisionWithTerrain(std::pair<double, double>& currentOffset, double deltaX, double deltaY);

    void handleClicks(const std::pair<int, int>& mousePos);

private:
    bool lmbPressed_;
    std::shared_ptr<GameBoard> gameBoard_;
    std::shared_ptr<EngineBase> engineBase_;
    std::shared_ptr<Player> player_;
};


#endif //GAMEOBJECTCONTROLLER_H

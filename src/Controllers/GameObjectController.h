//
// Created by eal on 12/5/24.
//

#ifndef GAMEOBJECTCONTROLLER_H
#define GAMEOBJECTCONTROLLER_H
#include <memory>
#include <vector>

#include "../Objects/Player.h"
#include "EngineBase/EngineBase.h"


class GameObjectController
{
public:
    explicit GameObjectController(std::shared_ptr<EngineBase>& engineBase);
    void handleMovement(double deltaTime);

private:
    std::shared_ptr<EngineBase> engineBase_;
    std::shared_ptr<Player> player_;
};


#endif //GAMEOBJECTCONTROLLER_H

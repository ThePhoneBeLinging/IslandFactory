//
// Created by eal on 12/5/24.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <memory>

#include "EngineBase/EngineBase.h"
#include "Objects/Player.h"


class GameController
{
public:
    explicit GameController(std::shared_ptr<EngineBase> engineBase);
    void update(double deltaTime);
private:
    void handleInput(double deltaTime);
    std::shared_ptr<Player> player_;
    std::shared_ptr<EngineBase> engineBase_;
};



#endif //GAMECONTROLLER_H

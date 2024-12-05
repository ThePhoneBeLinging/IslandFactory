//
// Created by eal on 12/5/24.
//

#include "GameController.h"

#include <utility>

GameController::GameController(std::shared_ptr<EngineBase> engineBase) : player_(std::make_shared<Player>()), engineBase_(std::move(engineBase))
{
    engineBase_->registerDrawAble(player_);
}

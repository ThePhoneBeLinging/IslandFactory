//
// Created by eal on 12/5/24.
//

#include "GameController.h"
#include <utility>

GameController::GameController(std::shared_ptr<EngineBase>& engineBase)
        : engineBase_(engineBase), gameObjectController_(std::make_unique<GameObjectController>(engineBase)),
ui_(std::make_shared<UI>(engineBase)), inventoryController_(std::make_shared<InventoryController>(engineBase)),
hoverController_(std::make_shared<HoverController>())
{
}

void GameController::update(const double deltaTime)
{
    handleInput(deltaTime);
    ui_->updateLocationInCaseOfResize();
}

void GameController::handleInput(const double deltaTime)
{
    const auto mousePos = engineBase_->getGraphicsLibrary()->getMousePos();
    auto activePlaceAble = inventoryController_->getSelectedPlaceAble();
    if (activePlaceAble == nullptr)
    {
        gameObjectController_->handlePlayModeClicks(mousePos);
    }
    else
    {
        gameObjectController_->handleBuildModeClicks(mousePos,activePlaceAble);
        hoverController_->handleHovering(mousePos,engineBase_->getSceneController()->getCurrentDrawAbleController()->getCurrentUpdateOffset(),activePlaceAble);
    }
    gameObjectController_->handleMovement(deltaTime);
}

//
// Created by eal on 12/5/24.
//

#include "GameController.h"
#include <utility>

GameController::GameController(std::shared_ptr<EngineBase>& engineBase)
        : engineBase_(engineBase), gameObjectController_(std::make_unique<GameObjectController>(engineBase)),
        inventoryController_(std::make_shared<InventoryController>(engineBase)),hoverController_(std::make_shared<HoverController>())
{
}

void GameController::update(const double deltaTime)
{
    handleInput(deltaTime);
}

void GameController::handleInput(const double deltaTime)
{
    auto mousePos = engineBase_->getGraphicsLibrary()->getMousePos();
    gameObjectController_->handleMovement(deltaTime);
    gameObjectController_->handleClicks(mousePos);
    hoverController_->handleHovering(mousePos,inventoryController_->getSelectedPlaceAble());
}

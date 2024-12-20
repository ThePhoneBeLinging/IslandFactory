//
// Created by eal on 12/20/24.
//

#include "InventoryController.h"

#include "PlaceAbles/CoalPlaceAble.h"

InventoryController::InventoryController(const std::shared_ptr<EngineBase>& engineBase)
{
    placeAbles_.push_back(std::make_shared<CoalPlaceAble>());

    // TODO Implement proper inventory system
    engineBase->registerDrawAble(placeAbles_[0]->getTileByReference());
}

std::shared_ptr<PlaceAble>& InventoryController::getSelectedPlaceAble()
{
    // TODO Implement
    return placeAbles_[0];
}

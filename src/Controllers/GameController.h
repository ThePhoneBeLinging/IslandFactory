//
// Created by eal on 12/5/24.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <memory>

#include "GameObjectController.h"
#include "HoverController.h"
#include "InventoryController.h"
#include "EngineBase/EngineBase.h"
#include "UI/UI.h"


class GameController
{
public:
    explicit GameController(std::shared_ptr<EngineBase>& engineBase);
    void update(double deltaTime);

private:
    void handleInput(double deltaTime);
    std::shared_ptr<EngineBase> engineBase_;
    std::unique_ptr<GameObjectController> gameObjectController_;
    std::shared_ptr<UI> ui_;
    std::shared_ptr<InventoryController> inventoryController_;
    std::shared_ptr<HoverController> hoverController_;
};


#endif //GAMECONTROLLER_H

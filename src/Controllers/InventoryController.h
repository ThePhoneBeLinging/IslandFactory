//
// Created by eal on 12/20/24.
//

#ifndef INVENTORYCONTROLLER_H
#define INVENTORYCONTROLLER_H
#include <memory>
#include <vector>
#include <EngineBase/EngineBase.h>

#include "PlaceAbles/PlaceAble.h"


class InventoryController
{
public:
    explicit InventoryController(std::shared_ptr<EngineBase>& engineBase);
    std::shared_ptr<PlaceAble>& getSelectedPlaceAble();
private:
    std::vector<std::shared_ptr<PlaceAble>> placeAbles_;
};



#endif //INVENTORYCONTROLLER_H

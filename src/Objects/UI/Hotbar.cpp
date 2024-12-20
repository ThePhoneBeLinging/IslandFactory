//
// Created by Elias Aggergaard Larsen on 20/12/2024.
//

#include "Hotbar.h"

#include <TextureList.h>

#include "ZValues.h"

Hotbar::Hotbar(std::shared_ptr<EngineBase>& engineBase) : amountOfSlots_(8),engineBase_(engineBase)
{
    for (int i = 0; i < amountOfSlots_; i++)
    {
        emptySlots_.push_back(std::make_shared<DrawAble>());
        emptySlots_.back()->setSize(50,50);
        emptySlots_.back()->setPositionIsAffectedByOffset(false);
        emptySlots_.back()->setZ(ZValues::UIZ);
        emptySlots_.back()->setTextureLocation(&TextureList::itemSlot);
        engineBase->registerDrawAble(emptySlots_.back());
    }
    placeAblesInSlots_.resize(amountOfSlots_);
}

void Hotbar::updateLocationInCaseOfResize()
{
    auto windowSize = engineBase_->getGraphicsLibrary()->getWindowSize();
    int x = windowSize.first / 2 - (amountOfSlots_ * 30);
    int y = windowSize.second - 100;
    for (int i = 0; i < amountOfSlots_; i++)
    {
        emptySlots_[i]->setPosition(x,y);
        x += 60;
    }
}

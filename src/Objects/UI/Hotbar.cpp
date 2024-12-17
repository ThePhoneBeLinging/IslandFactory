//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#include "Hotbar.h"

#include <TextureList.h>

Hotbar::Hotbar(std::shared_ptr<EngineBase>& engineBase) : engineBase_(engineBase) ,emptyHotbar_(std::make_shared<DrawAble>())
{
    emptyHotbar_->setTextureLocation(&TextureList::hotbar);
    // TODO should size scale by window?
    // If so, should this even be handled here?
    emptyHotbar_->setSize(750,500);
    auto windowLocation = engineBase_->getGraphicsLibrary()->getWindowSize();
    emptyHotbar_->setPosition((windowLocation.first / 2) - (emptyHotbar_->getWidth() / 2), windowLocation.second - 350);
    emptyHotbar_->setPositionIsAffectedByOffset(false);
    engineBase_->registerDrawAble(emptyHotbar_);
}

//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#include "Hotbar.h"

#include <TextureList.h>

Hotbar::Hotbar() : emptyHotbar_(std::make_unique<DrawAble>())
{
    emptyHotbar_->setTextureLocation(&TextureList::hotbar);
}

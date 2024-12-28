//
// Created by magnu on 26-12-2024.
//

#include "Factory.h"

#include <iostream>
#include <TextureList.h>
#include <EngineBase/EngineBase.h>

#include "ZValues.h"

Factory::Factory(std::shared_ptr<EngineBase>& _enginebase): engineBase(_enginebase)
{
    setTextureLocation(&TextureList::factory);
}

void Factory::onClick()
{
    createFactoryMenu(engineBase);
}

void Factory::createFactoryMenu(std::shared_ptr<EngineBase> &engine_base)
{
    //std::cout << "Dean" << std::endl;
    _menuDrawable = std::make_shared<DrawAble>();
    _menuDrawable->setSize(50, 50);
    _menuDrawable->setPosition(6 * TILESIZE,10 * TILESIZE - TILESIZE);
    _menuDrawable->setTextureLocation(&TextureList::coalOre);
    _menuDrawable->setZ(ZValues::FACTORYZ);
    engine_base->registerDrawAble(_menuDrawable);
}

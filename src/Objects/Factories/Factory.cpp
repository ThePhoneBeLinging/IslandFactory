//
// Created by magnu on 26-12-2024.
//

#include "Factory.h"

#include <iostream>
#include <TextureList.h>
#include <EngineBase/EngineBase.h>

Factory::Factory()
{
    setTextureLocation(&TextureList::factory);
}

void Factory::onClick()
{
    uint8_t iterator = 5;
    while (iterator > 0)
    {
        if (auto enginebase = enginebase_.lock())
        {
            createFactoryMenu(enginebase);
        }
        iterator--;
    }


}

void Factory::createFactoryMenu(std::shared_ptr<EngineBase> &engine_base)
{
    std::cout << "Dean" << std::endl;
    _menuDrawable = std::make_shared<DrawAble>();
    _menuDrawable->setSize(20,20);

    engine_base->registerDrawAble(_menuDrawable);

}

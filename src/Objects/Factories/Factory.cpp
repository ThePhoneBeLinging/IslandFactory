//
// Created by magnu on 26-12-2024.
//

#include "Factory.h"

#include <iostream>
#include <TextureList.h>

Factory::Factory()
{
    setTextureLocation(&TextureList::factory);
}

void Factory::onClick()
{
    std::cout << "Da factory has been clicked!" << std::endl;
}

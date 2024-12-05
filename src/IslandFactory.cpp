//
// Created by eal on 12/5/24.
//

#include "IslandFactory.h"
#include <iostream>
void IslandFactory::launch()
{
    engineBase_ = std::make_shared<EngineBase>();
    engineBase_->registerUpdateFunction(&update);
    engineBase_->launch();
}

void IslandFactory::update(const double deltaTime)
{
    std::cout << "Update func: " << deltaTime << std::endl;
}

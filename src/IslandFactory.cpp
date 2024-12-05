//
// Created by eal on 12/5/24.
//

#include "IslandFactory.h"

IslandFactory::IslandFactory()
{
    engineBase_ = std::make_shared<EngineBase>();
}

void IslandFactory::start()
{
    engineBase_->launch();
}

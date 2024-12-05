//
// Created by eal on 12/5/24.
//

#include "IslandFactory.h"

IslandFactory::IslandFactory()
{
    engineBase_ = std::make_shared<EngineBase>();
    draw_able_ = std::make_shared<DrawAble>();
}

void IslandFactory::start()
{
    draw_island();
    engineBase_->launch();
}

void IslandFactory::draw_island() {
    draw_able_->setHeight(400);
    draw_able_->setWidth(400);
    draw_able_->setX(1200/2 - draw_able_->getWidth()/2);
    draw_able_->setY(800/2 - draw_able_->getHeight()/2);
    draw_able_->setTextureIndex(engineBase_->getGraphicsLibrary()->loadTexture("../../Resources/Island.png"));
    engineBase_->registerDrawAble(draw_able_);
}

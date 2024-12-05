#include "IslandFactory.h"

IslandFactory::IslandFactory()
{
    engineBase_ = std::make_shared<EngineBase>();
    draw_able_ = std::make_shared<DrawAble>();
}

void IslandFactory::start() const {
    Island main_island;
    main_island.setTexture(engineBase_, "Island");
    engineBase_->registerDrawAble(main_island.get_drawable());
    engineBase_->launch();
}


#include "IslandFactory.h"

IslandFactory::IslandFactory()
{
    engineBase_ = std::make_shared<EngineBase>();
    draw_able_ = std::make_shared<DrawAble>();
    main_island_ = std::make_shared<Island>();
}

void IslandFactory::start() const {

    main_island_->setHeight(main_island_->getHeight() + 500);
    main_island_->setTexture(engineBase_, "Island");
    engineBase_->registerDrawAble(main_island_->get_drawable());
    engineBase_->launch();
}


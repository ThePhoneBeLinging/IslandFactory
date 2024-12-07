#include "IslandFactory.h"

IslandFactory::IslandFactory()
{
    engineBase_ = std::make_shared<EngineBase>();
    draw_able_ = std::make_shared<DrawAble>();
    main_island_ = std::make_shared<Island>();
    second_island_ = std::make_shared<Island>();
}

void IslandFactory::start() const {
    engineBase_->registerDrawAble(createMainIsland());
    engineBase_->registerDrawAble(createSecondIsland());
    engineBase_->launch();
}

std::shared_ptr<DrawAble> IslandFactory::createMainIsland() const {
    main_island_->setSize(main_island_->getHeight() + 200, main_island_->getWidth(), true);
    main_island_->setX(main_island_->getX() + 100);
    main_island_->setY(main_island_->getY() + 100);
    main_island_->setTexture("Island");
    return main_island_->get_drawable();
}

std::shared_ptr<DrawAble> IslandFactory::createSecondIsland() const {
    second_island_->setSize(main_island_->getHeight() - 100, main_island_->getWidth(), true);
    second_island_->setX(main_island_->getX() + 100);
    second_island_->setY(main_island_->getY() + 100);
    second_island_->setTexture("Island2");
    return second_island_->get_drawable();

}



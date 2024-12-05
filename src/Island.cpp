#include "Island.h"

Island::Island() {
    island_draw_able_ = std::make_shared<DrawAble>();
    island_draw_able_->setHeight(400);
    island_draw_able_->setWidth(400);
    island_draw_able_->setX(1200/2 - island_draw_able_->getWidth()/2);
    island_draw_able_->setY(800/2 - island_draw_able_->getHeight()/2);
}

void Island::set_textureIndex(const std::shared_ptr<EngineBase>& _enginebase) const {
    island_draw_able_->setTextureIndex(_enginebase->getGraphicsLibrary()->loadTexture("../../Resources/Island.png"));
}

std::shared_ptr<DrawAble> Island::get_drawable() {
    return island_draw_able_;
}

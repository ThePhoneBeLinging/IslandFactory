#include "Island.h"

Island::Island() {
    island_draw_able_ = std::make_shared<DrawAble>();

    island_draw_able_->setHeight(height);
    island_draw_able_->setWidth(width);
    island_draw_able_->setX(x - static_cast<double>(island_draw_able_->getWidth())/2);
    island_draw_able_->setY(y - static_cast<double>(island_draw_able_->getHeight())/2);
}

void Island::setTexture(const std::shared_ptr<EngineBase>& _enginebase, const std::string& image) const {
    island_draw_able_->setTextureIndex(_enginebase->getGraphicsLibrary()->loadTexture("../../Resources/" + image + ".png"));
}

void Island::setX(const double _x) {
    x = _x;
}

void Island::setY(const double _y) {
    y = _y;
}

double Island::getX() const {
    return x;
}

double Island::getY() const {
    return y;
}

void Island::setHeight(const int _height) {
    height = _height;
}

void Island::setWidth(const int _width) {
    width = _width;
}

int Island::getHeight() const {
    return height;
}

int Island::getWidth() const {
    return width;
}

std::shared_ptr<DrawAble> Island::get_drawable() {
    return island_draw_able_;
}

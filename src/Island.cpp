#include "Island.h"

Island::Island() {
    island_draw_able_ = std::make_shared<DrawAble>();

    island_draw_able_->setHeight(height);
    island_draw_able_->setWidth(width);
    island_draw_able_->setX(x - static_cast<double>(island_draw_able_->getWidth())/2);
    island_draw_able_->setY(y - static_cast<double>(island_draw_able_->getHeight())/2);

    aspect = static_cast<double>(island_draw_able_->getWidth()) / island_draw_able_->getHeight();
    is_clicked = false;
}

void Island::setTexture(const std::string& image) const {
    island_draw_able_->setTextureLocation("../../Resources/" + image + ".png");
}

void Island::setX(const double _x) {
    island_draw_able_->setX(_x);
}

void Island::setY(const double _y) {
    island_draw_able_->setY(_y);
}

double Island::getX() const {
    return island_draw_able_->getX();
}

double Island::getY() const {
    return island_draw_able_->getY();
}

void Island::setHeight(const int _height) {
    island_draw_able_->setHeight(_height);
}

void Island::setWidth(const int _width) {
    island_draw_able_->setWidth(_width);
}

int Island::getHeight() const {
    return island_draw_able_->getHeight();
}

int Island::getWidth() const {
    return island_draw_able_->getWidth();
}

std::shared_ptr<DrawAble> Island::get_drawable() {
    return island_draw_able_;
}

void Island::setClickState(const bool _newClickstate) {
    is_clicked = _newClickstate;
}

bool Island::getClickState() const {
    return is_clicked;
}

void Island::setSize(double _height, double _width, bool _useAspect) {
    if (_useAspect){
        double aspectRatio = _width / _height;

        if (aspectRatio > 0) {
            setWidth(_height * static_cast<int>(aspectRatio));
            setHeight(_height);
        } else {
            return;
        }
    } else {
        setWidth(_width);
        setHeight(_height);
    }
}

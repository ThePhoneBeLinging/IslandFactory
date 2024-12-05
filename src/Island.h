#ifndef ISLAND_H
#define ISLAND_H
#include "EngineBase/DrawAble.h"
#include "EngineBase/EngineBase.h"
#include <String>


class Island{
public:
    Island();

    void setTexture(const std::shared_ptr<EngineBase> &_enginebase, const std::string& image) const;

    void setX(double _x);
    void setY(double _y);
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;

    void setHeight(int _height);
    void setWidth(int _width);
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getWidth() const;

    std::shared_ptr<DrawAble> get_drawable();

private:
    std::shared_ptr<DrawAble> island_draw_able_;
    int width = 100;
    int height = 100;
    double aspect;
    double x = 200;
    double y = 200;
};



#endif //ISLAND_H

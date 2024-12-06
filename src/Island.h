#ifndef ISLAND_H
#define ISLAND_H
#include "EngineBase/DrawAble.h"
#include "EngineBase/EngineBase.h"
#include <String>


class Island {
public:
    Island();

    void setTexture(const std::string& image) const;

    void setX(double _x);
    void setY(double _y);
    [[nodiscard]] double getX() const;
    [[nodiscard]] double getY() const;

    void setHeight(double _height);
    void setWidth(double _width);
    [[nodiscard]] double getHeight() const;
    [[nodiscard]] double getWidth() const;

    void setSize(double _height, double _width, bool _useAspect);

    std::shared_ptr<DrawAble> get_drawable();

    void setClickState(bool _newClickstate);
    [[nodiscard]] bool getClickState() const;

private:
    std::shared_ptr<DrawAble> island_draw_able_;
    int width = 100;
    int height = 100;
    double aspect;
    double x = 200;
    double y = 200;
    bool is_clicked;

};



#endif //ISLAND_H

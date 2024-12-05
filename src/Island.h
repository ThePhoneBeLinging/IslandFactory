#ifndef ISLAND_H
#define ISLAND_H
#include "EngineBase/DrawAble.h"
#include "EngineBase/EngineBase.h"
#include <String>


class Island{
public:
    Island();

    void setTextureIndex(const std::shared_ptr<EngineBase> &_enginebase, const std::string& image) const;

    std::shared_ptr<DrawAble> get_drawable();

private:
    std::shared_ptr<DrawAble> island_draw_able_;
    double x = 0;
    double y = 0;
    int width = 0;
    int height = 0;
};



#endif //ISLAND_H

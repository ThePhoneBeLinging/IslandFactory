#ifndef ISLAND_H
#define ISLAND_H
#include "EngineBase/DrawAble.h"
#include "EngineBase/EngineBase.h"
#include <String>


class Island : public DrawAble{
public:
    Island();

    void setTextureIndex(const std::shared_ptr<EngineBase> &_enginebase, std::string image) const;

    std::shared_ptr<DrawAble> get_drawable();

private:
    std::shared_ptr<DrawAble> island_draw_able_;
};



#endif //ISLAND_H

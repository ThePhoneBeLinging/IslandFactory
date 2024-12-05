#ifndef ISLAND_H
#define ISLAND_H
#include "EngineBase/DrawAble.h"
#include "EngineBase/EngineBase.h"


class Island {
public:
    Island();

    void set_textureIndex(const std::shared_ptr<EngineBase>& _enginebase) const;
    std::shared_ptr<DrawAble> get_drawable();
private:
    std::shared_ptr<DrawAble> island_draw_able_;
};



#endif //ISLAND_H

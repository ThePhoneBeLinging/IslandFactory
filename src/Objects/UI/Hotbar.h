//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#ifndef HOTBAR_H
#define HOTBAR_H
#include <memory>
#include <EngineBase/DrawAble.h>


class Hotbar
{
public:
    Hotbar();
private:
    std::unique_ptr<DrawAble> emptyHotbar_;
};



#endif //HOTBAR_H

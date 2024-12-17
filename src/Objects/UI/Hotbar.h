//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#ifndef HOTBAR_H
#define HOTBAR_H
#include <memory>
#include <EngineBase/DrawAble.h>
#include <EngineBase/EngineBase.h>


class Hotbar
{
public:
    explicit Hotbar(std::shared_ptr<EngineBase>& engineBase);
private:
    std::shared_ptr<EngineBase>& engineBase_;
    std::shared_ptr<DrawAble> emptyHotbar_;
};



#endif //HOTBAR_H

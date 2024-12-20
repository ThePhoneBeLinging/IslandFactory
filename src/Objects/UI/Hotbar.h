//
// Created by Elias Aggergaard Larsen on 20/12/2024.
//

#ifndef HOTBAR_H
#define HOTBAR_H
#include <vector>
#include <EngineBase/DrawAble.h>
#include <EngineBase/EngineBase.h>


class Hotbar
{
public:
    explicit Hotbar(std::shared_ptr<EngineBase>& engineBase);
    void updateLocationInCaseOfResize();
private:
    int amountOfSlots_;
    std::shared_ptr<EngineBase>& engineBase_;
    std::vector<std::shared_ptr<DrawAble>> emptySlots_;
};



#endif //HOTBAR_H

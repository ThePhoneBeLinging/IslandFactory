//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#ifndef UI_H
#define UI_H
#include <EngineBase/EngineBase.h>

#include "Hotbar.h"


class Ui
{
public:
    explicit Ui(std::shared_ptr<EngineBase>& engineBase);
private:
    std::shared_ptr<Hotbar> hotbar_;
};



#endif //UI_H

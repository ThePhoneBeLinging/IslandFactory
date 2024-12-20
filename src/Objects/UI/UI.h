//
// Created by Elias Aggergaard Larsen on 20/12/2024.
//

#ifndef UI_H
#define UI_H
#include <EngineBase/EngineBase.h>

#include "Hotbar.h"


class UI
{
public:
    explicit UI(std::shared_ptr<EngineBase>& engineBase);
    void updateLocationInCaseOfResize();
private:
    std::shared_ptr<Hotbar> hotbar_;
};



#endif //UI_H

//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#ifndef UI_H
#define UI_H
#include "Hotbar.h"


class Ui
{
public:
    Ui();
private:
    std::shared_ptr<Hotbar> hotbar_;
};



#endif //UI_H

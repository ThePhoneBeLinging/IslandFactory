//
// Created by eal on 12/19/24.
//

#ifndef HOVERCONTROLLER_H
#define HOVERCONTROLLER_H
#include <memory>
#include <utility>

#include "PlaceAbles/PlaceAble.h"


class HoverController
{
public:
    HoverController() = default;
private:
    void handleHovering(std::pair<int,int>& mousePos, std::shared_ptr<PlaceAble>& placeAble);
};



#endif //HOVERCONTROLLER_H

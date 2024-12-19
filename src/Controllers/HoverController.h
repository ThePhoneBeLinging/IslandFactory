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
    void handleHovering(const std::pair<int,int>& mousePos, const std::pair<double,double>& currentOffset, std::shared_ptr<PlaceAble>& placeAble);
};



#endif //HOVERCONTROLLER_H

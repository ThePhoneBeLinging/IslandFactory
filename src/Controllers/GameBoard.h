//
// Created by eal on 12/5/24.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <memory>
#include <vector>

#include "EngineBase/EngineBase.h"


class GameBoard
{
public:
    explicit GameBoard(std::shared_ptr<EngineBase>& engineBase);

private:
    std::shared_ptr<EngineBase> engineBase_;
};


#endif //GAMEBOARD_H

//
// Created by eal on 12/5/24.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <memory>
#include <vector>

#include "Tiles/Tile.h"
#include "EngineBase/EngineBase.h"


class GameBoard
{
public:
    explicit GameBoard(std::shared_ptr<EngineBase>& engineBase);

    std::shared_ptr<Tile>& getTile(int firstIndex, int secondIndex);

    int getGridSideLength();

    void handleClicks(const std::pair<int, int>& mousePosition);

private:
    std::vector<std::vector<std::shared_ptr<Tile>>> tileMatrix_;
    std::shared_ptr<EngineBase> engineBase_;
};


#endif //GAMEBOARD_H

//
// Created by eal on 12/5/24.
//

#include "GameBoard.h"

#include "../Objects/Tiles/GrassTile.h"
#include "EngineBase/EngineBase.h"

GameBoard::GameBoard(std::shared_ptr<EngineBase>& engineBase) : engineBase_(engineBase)
{
    int y = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = 0;
        tileMatrix_.emplace_back();
        for (int j = 0; j < 10; j++)
        {
            tileMatrix_[i].emplace_back(std::make_shared<GrassTile>());
            tileMatrix_[i][j]->setX(x);
            tileMatrix_[i][j]->setY(y);
            engineBase_->registerDrawAble(tileMatrix_[i][j]);
            x += Tile::TILESIZE;
        }
        y += Tile::TILESIZE;
    }
}

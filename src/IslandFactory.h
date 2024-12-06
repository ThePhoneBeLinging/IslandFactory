#ifndef IslandFactory_H
#define IslandFactory_H
#include "EngineBase/EngineBase.h"
#include "Island.h"


class IslandFactory
{
public:
    IslandFactory();
    void start() const;
private:
    std::shared_ptr<EngineBase> engineBase_;
    std::shared_ptr<DrawAble> draw_able_;
    std::shared_ptr<Island> main_island_;
    std::shared_ptr<DrawAble> createMainIsland() const;
};

#endif //IslandFactory_H

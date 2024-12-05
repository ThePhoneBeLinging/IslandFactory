//
// Created by eal on 12/5/24.
//

#ifndef IslandFactory_H
#define IslandFactory_H
#include "EngineBase/EngineBase.h"


class IslandFactory
{
public:
    static void launch();

private:
    static void update(double deltaTime);
    static inline std::shared_ptr<EngineBase> engineBase_;
};



#endif //IslandFactory_H

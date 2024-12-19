#include "IslandFactory.h"

int main()
{
    auto gameEngineBase = std::make_shared<EngineBase>();
    auto factoryGame = IslandFactory(gameEngineBase);
    gameEngineBase->launch();
    return 0;
}

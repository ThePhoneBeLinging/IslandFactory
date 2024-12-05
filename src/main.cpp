#include "IslandFactory.h"
#include "EngineBase/EngineBase.h"

int main()
{
    auto const keeper = std::make_unique<IslandFactory>();
    keeper->start();
    return 0;
}

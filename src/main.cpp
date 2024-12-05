#include <iostream>

#include "IslandFactory.h"
#include "EngineBase/EngineBase.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    auto keeper = std::make_unique<IslandFactory>();
    keeper->start();
    return 0;
}

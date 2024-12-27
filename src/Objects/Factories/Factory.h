//
// Created by magnu on 26-12-2024.
//

#ifndef FACTORY_H
#define FACTORY_H
#include <EngineBase/EngineBase.h>
#include <Tiles/Tile.h>


class Factory : public Tile
{
public:
    Factory();
    void onClick() override;
    void createFactoryMenu(std::shared_ptr<EngineBase> &engine_base);
private:
    std::shared_ptr<DrawAble> _menuDrawable;
};


#endif //FACTORY_H

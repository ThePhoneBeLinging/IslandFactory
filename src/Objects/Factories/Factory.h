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
    Factory(std::shared_ptr<EngineBase>& _enginebase);
    void onClick() override;
    void createFactoryMenu(std::shared_ptr<EngineBase> &engine_base);
private:
    std::shared_ptr<DrawAble> _menuDrawable;
    std::shared_ptr<EngineBase>& engineBase;
};


#endif //FACTORY_H

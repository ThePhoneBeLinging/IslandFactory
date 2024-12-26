//
// Created by magnu on 26-12-2024.
//

#ifndef FACTORY_H
#define FACTORY_H
#include <Tiles/Tile.h>


class Factory : public Tile
{
public:
    Factory();
    void onClick() override;
private:
};


#endif //FACTORY_H

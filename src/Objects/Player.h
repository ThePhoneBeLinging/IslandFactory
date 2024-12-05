//
// Created by eal on 12/5/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <EngineBase/DrawAble.h>


class Player : public DrawAble
{
public:
    Player();
    double getMovementSpeed() const;
private:
    double movementSpeed_;
};



#endif //PLAYER_H

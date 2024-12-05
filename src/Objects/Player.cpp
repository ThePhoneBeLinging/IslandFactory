//
// Created by eal on 12/5/24.
//

#include "Player.h"

Player::Player()
{
    height_ = 50;
    width_ = 50;
    movementSpeed_ = 500;
}

double Player::getMovementSpeed() const
{
    return movementSpeed_;
}

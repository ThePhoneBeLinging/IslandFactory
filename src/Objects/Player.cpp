//
// Created by eal on 12/5/24.
//

#include "Player.h"

#include "TextureList.h"

Player::Player()
{
    setHeight(50);
    setWidth(50);
    movementSpeed_ = 50000;
}

void Player::moveToCenter(const std::pair<int, int>& windowSize)
{
    updatePosition((windowSize.first - width_) / 2, (windowSize.second - height_) / 2);
}

double Player::getMovementSpeed() const
{
    return movementSpeed_;
}

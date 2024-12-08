//
// Created by eal on 12/5/24.
//

#include "Player.h"

#include "TextureList.h"

Player::Player()
{
    this->setSize(50, 50);
    movementSpeed_ = 500;
}

void Player::moveToCenter(const std::pair<int, int>& windowSize)
{
    updatePosition((windowSize.first - this->getWidth()) / 2, (windowSize.second - this->getHeight()) / 2);
}

double Player::getMovementSpeed() const
{
    return movementSpeed_;
}

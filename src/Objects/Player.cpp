//
// Created by eal on 12/5/24.
//

#include "Player.h"

#include <math.h>
#include <valarray>

#include "TextureList.h"
#include "ZValues.h"
#include "Tiles/Tile.h"

Player::Player()
{
    this->setSize(50, 50);
    this->setZ(ZValues::PLAYERZ);
    movementSpeed_ = 500;
    this->setPositionIsAffectedByOffset(false);
    this->setTextureLocation(&TextureList::zelda);
}

void Player::moveToCenter(const std::pair<int, int>& windowSize)
{
    setPosition((windowSize.first - this->getWidth()) / 2, (windowSize.second - this->getHeight()) / 2);
}

double Player::getMovementSpeed() const
{
    return movementSpeed_;
}

std::vector<std::pair<double, double>> Player::getCollisionTiles(std::pair<double, double>& currentOffset)
{
    // Order is:
    // 0: Middle X, Top Y
    // 1: Middle X, Bottom Y
    // 2: Left X, Middle Y
    // 3: Right X, Middle Y

    // AKA
    // 0: TOP
    // 1: BOTTOM
    // 2: LEFT
    // 3: RIGHT

    std::vector<std::pair<double, double>> tilesToCheck;
    tilesToCheck.emplace_back(this->getX() + (this->getWidth() / 2), this->getY());
    tilesToCheck.emplace_back(this->getX() + (this->getWidth() / 2),
                              this->getY() + this->getHeight());
    tilesToCheck.emplace_back(this->getX(), this->getY() + (this->getHeight()) / 2);
    tilesToCheck.emplace_back(this->getX() + this->getWidth(),
                              this->getY() + (this->getHeight()) / 2);
    return tilesToCheck;
}

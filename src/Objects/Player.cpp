//
// Created by eal on 12/5/24.
//

#include "Player.h"

#include "TextureList.h"
#include "Tiles/Tile.h"

Player::Player()
{
    this->setSize(50, 50);
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

std::vector<std::pair<int, int>> Player::getCollisionTiles(std::pair<double, double>& currentOffset)
{
    std::vector<std::pair<int, int>> tilesToCheck;
    tilesToCheck.emplace_back(this->getX() + (this->getWidth() / 2), this->getY());
    tilesToCheck.emplace_back(this->getX() + (this->getWidth() / 2),
                              this->getY() - this->getHeight());
    tilesToCheck.emplace_back(this->getX(), this->getY() - (this->getHeight()) / 2);
    tilesToCheck.emplace_back(this->getX() + this->getWidth(),
                              this->getY() - (this->getHeight()) / 2);
    for (auto& val: tilesToCheck)
    {
        val.first -= currentOffset.first;
        val.second -= currentOffset.second;
        val.first /= Tile::TILESIZE;
        val.second /= Tile::TILESIZE;
    }
    return tilesToCheck;
}

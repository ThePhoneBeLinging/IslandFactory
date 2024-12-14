//
// Created by eal on 12/5/24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <EngineBase/DrawAble.h>
#include <vector>


class Player : public DrawAble
{
public:
    Player();

    void moveToCenter(const std::pair<int, int>& windowSize);

    [[nodiscard]] double getMovementSpeed() const;

    std::vector<std::pair<double, double>> getCollisionTiles(std::pair<double, double>& currentOffset);

private:
    double movementSpeed_;
};


#endif //PLAYER_H

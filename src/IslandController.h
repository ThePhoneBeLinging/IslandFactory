#ifndef ISLANDCONTROLLER_H
#define ISLANDCONTROLLER_H
#include <memory>

#include "Island.h"


class IslandController {
public:
    IslandController();
    void connectIslands(const std::shared_ptr<Island> &_island1, const std::shared_ptr<Island> &_island2);

    [[nodiscard]] bool getConnected() const;
    void setConnected(bool _newConnection);

private:
    bool is_connected;
};



#endif //ISLANDCONTROLLER_H

#include "IslandController.h"

IslandController::IslandController() {
    is_connected = false;
}

void IslandController::connectIslands(const std::shared_ptr<EngineBase>& _enginebase, const std::shared_ptr<Island> &_island1, const std::shared_ptr<Island> &_island2) {
    if (_island1->getClickState() && _island2->getClickState()) {
        is_connected = true;
        drawIslandBridge(_enginebase, _island1, _island1);
    }
}

bool IslandController::getConnected() const {
    return is_connected;
}

void IslandController::setConnected(const bool _newConnection) {
    is_connected = _newConnection;
}

void IslandController::drawIslandBridge(const std::shared_ptr<EngineBase>& _enginebase, const std::shared_ptr<Island> &_island1, const std::shared_ptr<Island> &_island2) const {

}





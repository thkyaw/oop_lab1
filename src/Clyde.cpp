#include "../include/Clyde.hpp"
#include <algorithm>

Clyde::Clyde(std::string id, Point position) : Character(id, position) {}

void Clyde::DoBehavior() {
    DoBehavior(this->GetPosition());
}

void Clyde::DoBehavior(const Point& referencePosition) {
    if (referencePosition.x == position.x) {
        position.y -= 2;
    } else if (referencePosition.y == position.y) {
        position.x -= 2;
    } else {
        position.x -= 3;
        position.y -= 3;
    }

    position.x = std::clamp(position.x, 0, 15);
    position.y = std::clamp(position.y, 0, 15);
}
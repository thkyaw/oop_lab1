#include "../include/Blinky.hpp"
#include <algorithm>

Blinky::Blinky(std::string id, Point position) : Character(id, position) {}

void Blinky::DoBehavior() {
    switch (direction) {
        case 0:
            position.y += 3;
            if (position.y >= 15) {
                position.y = 15;
                direction = 1;
            }
            break;
        case 1:
            position.x += 3;
            if (position.x >= 15) {
                position.x = 15;
                direction = 2;
            }
            break;
        case 2:
            position.x -= 3;
            position.y -= 3;
            if (position.x <= 0 && position.y <= 0) {
                position.x = 0;
                position.y = 0;
                direction = 0;
            }
            break;
    }
    position.x = std::clamp(position.x, 0, 15);
    position.y = std::clamp(position.y, 0, 15);
}

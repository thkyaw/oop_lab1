#include "../include/Pacman.hpp"
#include <iostream>
#include <algorithm>

Pacman::Pacman(std::string id, Point position) : Character(id, position) {}

void Pacman::DoBehavior() {
    char input;
    std::cin >> input;
    switch (input) {
    case 'W': position.y += 3; break;
    case 'S': position.y -= 3; break;
    case 'A': position.x -= 3; break;
    case 'D': position.x += 3; break;
    default: break;
    }

    position.x = std::clamp(position.x, 0, 15);
    position.y = std::clamp(position.y, 0, 15);
}
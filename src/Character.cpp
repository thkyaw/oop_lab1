#include "../include/Character.hpp"

Character::Character(std::string id, Point position) : id(id), position(position) {}

Character::~Character() {}

void Character::DoBehavior(const Point &referencePosition) {}

std::string Character::GetId() const {
    return id;
}

Point Character::GetPosition() const {
    return position;
}
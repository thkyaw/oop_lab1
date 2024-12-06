#ifndef BLINKY_HPP
#define BLINKY_HPP

#include "Character.hpp"

class Blinky : public Character {
private:
    int direction = 0;
public:
    Blinky(std::string id, Point position);
    void DoBehavior() override;
};

#endif
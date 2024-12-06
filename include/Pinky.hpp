#ifndef PINKY_HPP
#define PINKY_HPP

#include "Character.hpp"

class Pinky : public Character {
private:
  int direction = 0;
public:
  Pinky(std::string id, Point position);
  void DoBehavior() override;
};

#endif
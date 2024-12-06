#ifndef INKY_HPP
#define INKY_HPP

#include "Character.hpp"

class Inky : public Character {
private:
  int direction = 0;
public:
  Inky(std::string id, Point position);
  void DoBehavior() override;
};

#endif
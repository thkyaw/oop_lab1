#ifndef Clyde_HPP
#define Clyde_HPP

#include "Character.hpp"

class Clyde : public Character {
public:
  Clyde(std::string id, Point position);
  void DoBehavior() override;
  void DoBehavior(const Point& referencePosition);
};

#endif
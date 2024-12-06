#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

struct Point{
    int x = 0;
    int y = 0;
    Point(int x,int y) : x(x),y(y) {}
};

class Character {
protected:
    std::string id;
    Point position;
public:
    Character(std::string id, Point position);
    virtual ~Character();
    virtual void DoBehavior() = 0;
    virtual void DoBehavior(const Point& referencePosition);
    Point GetPosition() const;
    std::string GetId() const;

};

#endif
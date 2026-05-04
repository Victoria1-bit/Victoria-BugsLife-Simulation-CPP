#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <list>
#include <utility>
#include <string>

enum Direction { NORTH = 1, EAST, SOUTH, WEST };

class Bug {
protected:
    int id;
    std::pair<int,int> position;
    Direction direction;
    int health;
    bool alive;

    std::list<std::pair<int,int> > path;

public:
    Bug(int id, int x, int y, Direction dir, int health);

    virtual void move() = 0;
    virtual void display() const;

    bool isAlive() const;
    int getId() const;
    int getHealth() const;
    std::pair<int,int> getPosition() const;
    std::list<std::pair<int,int> > getPath() const;

    bool isWayBlocked();

    void setDirection(Direction dir);
    void kill();

    virtual ~Bug();
};

#endif
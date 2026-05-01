#ifndef BUG_H
#define BUG_H

#include <iostream>
#include <list>
#include <utility>

using namespace std;

// Direction enum (1–4)
enum Direction { NORTH = 1, EAST, SOUTH, WEST };

class Bug {
protected:
    int id;
    pair<int,int> position;
    Direction direction;
    int health;
    bool alive;

    list<pair<int,int>> path;

public:
    Bug(int id, int x, int y, Direction dir, int health);

    virtual void move() = 0;
    virtual void display() const;

    bool isAlive() const;
    int getId() const;
    pair<int,int> getPosition() const;

    bool isWayBlocked();

    // NEW: allows Board to change direction
    void setDirection(Direction dir);

    virtual ~Bug();
};

#endif
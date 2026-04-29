#ifndef BUG_H
#define BUG_H

#include <list>
#include <utility>

// Direction enum (simple and clear)
enum Direction { NORTH = 1, EAST, SOUTH, WEST };

class Bug {
protected:
    int id;
    std::pair<int,int> position;
    Direction direction;
    int health;
    bool alive;
    std::list<std::pair<int,int>> path;

public:
    // Constructor
    Bug(int id, int x, int y, Direction dir, int health);

    // Pure virtual function (makes class abstract)
    virtual void move() = 0;

    // Getters
    bool isAlive() const;
    int getId() const;
    std::pair<int,int> getPosition() const;

    // Check if bug is blocked by edge
    bool isWayBlocked();

    // Display bug info
    virtual void display() const;

    // Destructor
    virtual ~Bug();
};

#endif
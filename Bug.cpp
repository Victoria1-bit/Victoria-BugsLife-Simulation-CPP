#include "Bug.h"
#include <iostream>

// Constructor: sets up a new bug
Bug::Bug(int id, int x, int y, Direction dir, int health)
{
    this->id = id;
    this->position = {x, y};
    this->direction = dir;
    this->health = health;
    this->alive = true;

    // store starting position in path history
    path.push_back(position);
}

// Returns true if bug is alive
bool Bug::isAlive() const {
    return alive;
}

// Returns bug ID
int Bug::getId() const {
    return id;
}

// Returns current position
std::pair<int,int> Bug::getPosition() const {
    return position;
}

// Checks if bug is facing a wall
bool Bug::isWayBlocked() {
    int x = position.first;
    int y = position.second;

    if (direction == NORTH && y == 0) return true;
    if (direction == SOUTH && y == 9) return true;
    if (direction == WEST && x == 0) return true;
    if (direction == EAST && x == 9) return true;

    return false;
}

// Displays basic bug info
void Bug::display() const {
    std::cout << id << " (" << position.first << "," << position.second << ") ";
}

// Destructor
Bug::~Bug() {}
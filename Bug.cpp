#include "Bug.h"
#include <iostream>
#include <utility>

// Constructor
Bug::Bug(int id, int x, int y, Direction dir, int health)
{
    this->id = id;

    // FIX: use make_pair (safer for your compiler)
    this->position = std::make_pair(x, y);

    this->direction = dir;
    this->health = health;
    this->alive = true;

    // Save starting position
    path.push_back(position);
}

// Returns true if alive
bool Bug::isAlive() const {
    return alive;
}

// Returns ID
int Bug::getId() const {
    return id;
}

// Returns position
std::pair<int,int> Bug::getPosition() const {
    return position;
}

// Check if bug is facing a wall
bool Bug::isWayBlocked() {
    int x = position.first;
    int y = position.second;

    if (direction == NORTH && y == 0) return true;
    if (direction == SOUTH && y == 9) return true;
    if (direction == WEST && x == 0) return true;
    if (direction == EAST && x == 9) return true;

    return false;
}

// Display basic info
void Bug::display() const {
    std::cout << id << " (" << position.first << "," << position.second << ") ";
}

// Destructor
Bug::~Bug() {}
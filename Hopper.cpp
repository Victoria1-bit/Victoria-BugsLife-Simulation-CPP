#include "Hopper.h"
#include <iostream>
#include <cstdlib>

// Constructor: sets up a Hopper bug
Hopper::Hopper(int id, int x, int y, Direction dir, int health, int hopLength)
    : Bug(id, x, y, dir, health)
{
    this->hopLength = hopLength;
}

// Moves the hopper several steps in its current direction
void Hopper::move() {
    if (!alive) {
        return;
    }

    // If the hopper is facing a wall, choose another direction
    while (isWayBlocked()) {
        direction = static_cast<Direction>((rand() % 4) + 1);
    }

    // Move one step at a time so it can stop at a wall
    for (int i = 0; i < hopLength; i++) {
        if (isWayBlocked()) {
            break;
        }

        if (direction == NORTH) {
            position.second--;
        }
        else if (direction == EAST) {
            position.first++;
        }
        else if (direction == SOUTH) {
            position.second++;
        }
        else if (direction == WEST) {
            position.first--;
        }
    }

    path.push_back(position);
}

// Displays all Hopper details
void Hopper::display() const {
    std::cout << id << " Hopper "
              << "(" << position.first << "," << position.second << ") "
              << health << " ";

    if (direction == NORTH) {
        std::cout << "North ";
    }
    else if (direction == EAST) {
        std::cout << "East ";
    }
    else if (direction == SOUTH) {
        std::cout << "South ";
    }
    else if (direction == WEST) {
        std::cout << "West ";
    }

    std::cout << hopLength << " ";

    if (alive) {
        std::cout << "Alive";
    }
    else {
        std::cout << "Dead";
    }

    std::cout << std::endl;
}
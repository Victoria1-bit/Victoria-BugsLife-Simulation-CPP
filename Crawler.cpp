#include "Crawler.h"
#include <iostream>
#include <cstdlib>

// Constructor: uses the Bug constructor to set up shared values
Crawler::Crawler(int id, int x, int y, Direction dir, int health)
    : Bug(id, x, y, dir, health)
{
}

// Crawler moves one square in the direction it is facing
void Crawler::move() {
    // Dead bugs should not move
    if (!alive) {
        return;
    }

    // If the crawler is facing a wall, choose a new direction
    while (isWayBlocked()) {
        direction = static_cast<Direction>((rand() % 4) + 1);
    }

    // Move one square
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

    // Save the new position in the bug's path history
    path.push_back(position);
}

// Displays all crawler details in a readable way
void Crawler::display() const {
    std::cout << id << " Crawler "
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

    if (alive) {
        std::cout << "Alive";
    }
    else {
        std::cout << "Dead";
    }

    std::cout << std::endl;
}
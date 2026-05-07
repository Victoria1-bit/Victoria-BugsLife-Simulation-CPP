#include "DiagonalBug.h"
#include <iostream>
#include <cstdlib>

DiagonalBug::DiagonalBug(int id, int x, int y, Direction dir, int health)
        : Bug(id, x, y, dir, health) {
}

void DiagonalBug::move() {
    if (!alive) {
        return;
    }

    while (isWayBlocked()) {
        direction = static_cast<Direction>((rand() % 4) + 1);
    }

    if (direction == NORTH) {
        position.first++;
        position.second--;
    }
    else if (direction == EAST) {
        position.first++;
        position.second++;
    }
    else if (direction == SOUTH) {
        position.first--;
        position.second++;
    }
    else if (direction == WEST) {
        position.first--;
        position.second--;
    }

    if (position.first < 0) position.first = 0;
    if (position.first > 9) position.first = 9;
    if (position.second < 0) position.second = 0;
    if (position.second > 9) position.second = 9;

    path.push_back(position);
}

void DiagonalBug::display() const {
    std::cout << "Bug " << id
              << " DiagonalBug"
              << " | Pos: (" << position.first << "," << position.second << ")"
              << " | HP: " << health
              << " | " << (alive ? "Alive" : "Dead")
              << std::endl;
}
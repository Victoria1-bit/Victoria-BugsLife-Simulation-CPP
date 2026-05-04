#include "Bug.h"
#include <utility>

Bug::Bug(int id, int x, int y, Direction dir, int health) {
    this->id = id;
    this->position = std::make_pair(x, y);
    this->direction = dir;
    this->health = health;
    this->alive = true;

    path.push_back(position);
}

bool Bug::isAlive() const {
    return alive;
}

int Bug::getId() const {
    return id;
}

int Bug::getHealth() const {
    return health;
}

std::pair<int,int> Bug::getPosition() const {
    return position;
}

// NEW
std::list<std::pair<int,int> > Bug::getPath() const {
    return path;
}

void Bug::setDirection(Direction dir) {
    direction = dir;
}

void Bug::kill() {
    alive = false;
}

bool Bug::isWayBlocked() {
    int x = position.first;
    int y = position.second;

    if (direction == NORTH && y == 0) return true;
    if (direction == SOUTH && y == 9) return true;
    if (direction == WEST && x == 0) return true;
    if (direction == EAST && x == 9) return true;

    return false;
}

void Bug::display() const {
    std::cout << id << " (" << position.first << "," << position.second << ") "
              << health << " ";

    if (alive) std::cout << "Alive";
    else std::cout << "Dead";

    std::cout << std::endl;
}

Bug::~Bug() {}
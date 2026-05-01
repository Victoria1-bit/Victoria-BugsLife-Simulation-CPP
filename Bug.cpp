#include "Bug.h"

Bug::Bug(int id, int x, int y, Direction dir, int health) {
    this->id = id;
    position = {x, y};
    direction = dir;
    this->health = health;
    alive = true;

    path.push_back(position);
}

bool Bug::isAlive() const {
    return alive;
}

int Bug::getId() const {
    return id;
}

pair<int,int> Bug::getPosition() const {
    return position;
}

// NEW
void Bug::setDirection(Direction dir) {
    direction = dir;
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
    cout << id << " (" << position.first << "," << position.second << ") "
         << health << " ";

    if (alive)
        cout << "Alive";
    else
        cout << "Dead";

    cout << endl;
}

Bug::~Bug() {}
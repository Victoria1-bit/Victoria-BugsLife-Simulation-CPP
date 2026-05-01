#include "Bug.h"
#include <utility>

// Constructor: creates a bug with starting values
Bug::Bug(int id, int x, int y, Direction dir, int health) {
    this->id = id;
    this->position = std::make_pair(x, y);
    this->direction = dir;
    this->health = health;
    this->alive = true;

    // Store starting position
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

// Returns bug health
int Bug::getHealth() const {
    return health;
}

// Returns current position
std::pair<int,int> Bug::getPosition() const {
    return position;
}

// Changes bug direction
void Bug::setDirection(Direction dir) {
    direction = dir;
}

// Marks bug as dead
void Bug::kill() {
    alive = false;
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

// Basic display function
void Bug::display() const {
    std::cout << id << " (" << position.first << "," << position.second << ") "
              << health << " ";

    if (alive) {
        std::cout << "Alive";
    } else {
        std::cout << "Dead";
    }

    std::cout << std::endl;
}

// Destructor
Bug::~Bug() {}
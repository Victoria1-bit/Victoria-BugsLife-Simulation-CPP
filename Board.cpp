#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

// Load bugs from bugs.txt
void Board::loadBugsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::string line;

    // Read each bug record line by line
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        std::string value;

        int id;
        int x;
        int y;
        int dir;
        int health;
        int hopLength;

        getline(ss, type, ';');

        getline(ss, value, ';');
        id = stoi(value);

        getline(ss, value, ';');
        x = stoi(value);

        getline(ss, value, ';');
        y = stoi(value);

        getline(ss, value, ';');
        dir = stoi(value);

        getline(ss, value, ';');
        health = stoi(value);

        // C means Crawler
        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, (Direction)dir, health));
        }

        // H means Hopper
        else if (type == "H") {
            getline(ss, value, ';');
            hopLength = stoi(value);

            bugs.push_back(new Hopper(id, x, y, (Direction)dir, health, hopLength));
        }
    }
}

// Display every bug
void Board::displayAllBugs() const {
    for (auto bug : bugs) {
        bug->display();
    }
}

// Find one bug by ID
void Board::findBug(int id) const {
    for (auto bug : bugs) {
        if (bug->getId() == id) {
            bug->display();
            return;
        }
    }

    std::cout << "Bug " << id << " not found" << std::endl;
}

// Move all bugs once
void Board::tapBoard() {
    for (auto bug : bugs) {
        bug->move();
    }
}

// Randomly turn all bugs
void Board::turnBugs() {
    for (auto bug : bugs) {
        int newDirection = rand() % 4 + 1;
        bug->setDirection((Direction)newDirection);
    }
}

// Delete heap memory
Board::~Board() {
    for (auto bug : bugs) {
        delete bug;
    }
}
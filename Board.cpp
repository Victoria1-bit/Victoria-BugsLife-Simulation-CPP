#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

void Board::loadBugsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        std::string value;

        int id, x, y, dir, health, hop;

        getline(ss, type, ';');

        getline(ss, value, ';'); id = stoi(value);
        getline(ss, value, ';'); x = stoi(value);
        getline(ss, value, ';'); y = stoi(value);
        getline(ss, value, ';'); dir = stoi(value);
        getline(ss, value, ';'); health = stoi(value);

        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, (Direction)dir, health));
        }
        else if (type == "H") {
            getline(ss, value, ';'); hop = stoi(value);
            bugs.push_back(new Hopper(id, x, y, (Direction)dir, health, hop));
        }
    }
}

void Board::displayAllBugs() const {
    for (auto bug : bugs) {
        bug->display();
    }
}

void Board::tapBoard() {
    for (auto bug : bugs) {
        if (bug->isAlive()) bug->move();
    }
}

void Board::turnBugs() {
    for (auto bug : bugs) {
        if (bug->isAlive()) {
            int dir = rand() % 4 + 1;
            bug->setDirection((Direction)dir);
        }
    }
}

void Board::fightBugs() {
    for (int i = 0; i < bugs.size(); i++) {
        for (int j = i + 1; j < bugs.size(); j++) {

            if (bugs[i]->isAlive() && bugs[j]->isAlive()) {
                if (bugs[i]->getPosition() == bugs[j]->getPosition()) {

                    if (bugs[i]->getHealth() > bugs[j]->getHealth()) {
                        bugs[j]->kill();
                    }
                    else if (bugs[j]->getHealth() > bugs[i]->getHealth()) {
                        bugs[i]->kill();
                    }
                }
            }
        }
    }
}

void Board::findBug(int id) {
    for (auto bug : bugs) {
        if (bug->getId() == id) {
            bug->display();
            return;
        }
    }
    std::cout << "Bug not found." << std::endl;
}

// NEW (life history)
void Board::displayLifeHistory() const {
    for (auto bug : bugs) {
        std::cout << "Bug " << bug->getId() << " path: ";

        for (auto pos : bug->getPath()) {
            std::cout << "(" << pos.first << "," << pos.second << ") ";
        }

        std::cout << std::endl;
    }
}

Board::~Board() {
    for (auto bug : bugs) {
        delete bug;
    }
}
// Display all cells and bugs in each
void Board::displayAllCells() const {

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {

            std::cout << "(" << x << "," << y << "): ";

            bool found = false;

            for (auto bug : bugs) {
                if (bug->isAlive() && bug->getPosition() == std::make_pair(x, y)) {
                    std::cout << "Bug " << bug->getId() << " ";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "empty";
            }

            std::cout << std::endl;
        }
    }
}
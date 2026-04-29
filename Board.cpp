#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

#include <fstream>
#include <sstream>
#include <iostream>

// Load bugs from file
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

        getline(ss, type, ';');

        int id, x, y, dir, health, hop;

        getline(ss, line, ';'); id = stoi(line);
        getline(ss, line, ';'); x = stoi(line);
        getline(ss, line, ';'); y = stoi(line);
        getline(ss, line, ';'); dir = stoi(line);
        getline(ss, line, ';'); health = stoi(line);

        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, (Direction)dir, health));
        }
        else if (type == "H") {
            getline(ss, line, ';'); hop = stoi(line);
            bugs.push_back(new Hopper(id, x, y, (Direction)dir, health, hop));
        }
    }
}

// Display all bugs
void Board::displayAllBugs() const {
    for (auto bug : bugs) {
        bug->display();
    }
}

// Destructor (free memory)
Board::~Board() {
    for (auto bug : bugs) {
        delete bug;
    }
}
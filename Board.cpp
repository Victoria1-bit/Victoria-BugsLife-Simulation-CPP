#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

#include <fstream>
#include <sstream>
#include <iostream>

// Load bugs from a text file
void Board::loadBugsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::string line;

    // Read the file one line at a time
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;

        getline(ss, type, ';');

        int id;
        int x;
        int y;
        int dir;
        int health;
        int hop;

        getline(ss, line, ';');
        id = stoi(line);

        getline(ss, line, ';');
        x = stoi(line);

        getline(ss, line, ';');
        y = stoi(line);

        getline(ss, line, ';');
        dir = stoi(line);

        getline(ss, line, ';');
        health = stoi(line);

        // Create a Crawler if type is C
        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, (Direction)dir, health));
        }

        // Create a Hopper if type is H
        else if (type == "H") {
            getline(ss, line, ';');
            hop = stoi(line);

            bugs.push_back(new Hopper(id, x, y, (Direction)dir, health, hop));
        }
    }
}

// Display every bug on the board
void Board::displayAllBugs() const {
    for (auto bug : bugs) {
        bug->display();
    }
}

// Search for a bug by ID
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

// Delete all bugs from memory
Board::~Board() {
    for (auto bug : bugs) {
        delete bug;
    }
}
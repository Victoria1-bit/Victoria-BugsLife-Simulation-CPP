#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

void Board::loadBugsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error opening file" << endl;
        return;
    }

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string type;

        getline(ss, type, ',');

        int id, x, y, dir, health, hop;

        ss >> id;
        ss.ignore();
        ss >> x;
        ss.ignore();
        ss >> y;
        ss.ignore();
        ss >> dir;
        ss.ignore();
        ss >> health;

        if (type == "Crawler") {
            bugs.push_back(new Crawler(id, x, y, (Direction)dir, health));
        }
        else if (type == "Hopper") {
            ss.ignore();
            ss >> hop;
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
        bug->move();
    }
}

// NEW
void Board::turnBugs() {
    for (auto bug : bugs) {
        int newDir = rand() % 4 + 1;
        bug->setDirection((Direction)newDir);
    }
}
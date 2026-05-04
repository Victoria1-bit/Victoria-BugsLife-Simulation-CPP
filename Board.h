#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs;

public:
    void loadBugsFromFile(const std::string& filename);
    void displayAllBugs() const;
    void tapBoard();
    void turnBugs();
    void fightBugs();
    void findBug(int id);

    void displayLifeHistory() const;
    void displayAllCells() const;

    // NEW
    void runSimulation();

    ~Board();
};

#endif
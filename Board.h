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
    void findBug(int id) const;
    void tapBoard();
    void turnBugs();

    // Checks if bugs landed on the same cell
    void fightBugs();

    ~Board();
};

#endif
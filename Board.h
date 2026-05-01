#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Bug.h"

class Board {
private:
    // Vector stores pointers to all bugs
    std::vector<Bug*> bugs;

public:
    // Load bugs from bugs.txt file
    void loadBugsFromFile(const std::string& filename);

    // Display all bugs
    void displayAllBugs() const;

    // Find one bug by ID
    void findBug(int id) const;

    // Move all bugs once
    void tapBoard();

    // Destructor clears heap memory
    ~Board();
};

#endif
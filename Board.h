#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs; // stores all bugs

public:
    void loadBugsFromFile(const std::string& filename);
    void displayAllBugs() const;

    ~Board(); // destructor to clean memory
};

#endif
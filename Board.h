#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Bug.h"

using namespace std;

class Board {
private:
    vector<Bug*> bugs;

public:
    void loadBugsFromFile(const string& filename);
    void displayAllBugs() const;

    void tapBoard();

    // NEW
    void turnBugs();
};

#endif
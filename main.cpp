#include <iostream>
#include "Board.h"

using namespace std;

int main() {

    cout << "Bug Board Test" << endl;

    // Create board object
    Board board;

    // Load bugs from file (FIXED PATH)
    board.loadBugsFromFile("../bugs.txt");

    cout << "\nAll Bugs:" << endl;

    // Display all bugs
    board.displayAllBugs();

    return 0;
}
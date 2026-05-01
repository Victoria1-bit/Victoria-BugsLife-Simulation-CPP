#include <iostream>
#include "Board.h"

using namespace std;

int main() {

    // Starting message
    cout << "Bug Board Test" << endl;

    // Create board object
    Board board;

    // Load bugs from file
    board.loadBugsFromFile("bugs.txt");

    cout << "\nAll Bugs Before Tap:" << endl;

    // Display all bugs before movement
    board.displayAllBugs();

    cout << "\nTapping board..." << endl;

    // Move all bugs once
    board.tapBoard();

    cout << "\nAll Bugs After Tap:" << endl;

    // Display all bugs after movement
    board.displayAllBugs();

    return 0;
}
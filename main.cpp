#include <iostream>
#include "Board.h"

using namespace std;

int main() {

    // Starting message
    cout << "Bug Board Test" << endl;

    // Create the Board object (this will hold all bugs)
    Board board;

    // Load bugs from the text file
    // The file will be copied automatically into the build folder by CMake
    board.loadBugsFromFile("bugs.txt");

    cout << "\nAll Bugs:" << endl;

    // Display all bugs currently on the board
    board.displayAllBugs();

    return 0;
}
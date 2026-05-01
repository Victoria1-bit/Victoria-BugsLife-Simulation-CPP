#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

int main() {

    srand(time(0));

    cout << "Bug Board Test" << endl;

    Board board;

    // Load bugs from file
    board.loadBugsFromFile("bugs.txt");

    cout << "\nAll Bugs Before Tap:" << endl;
    board.displayAllBugs();

    cout << "\nTurning bugs..." << endl;
    board.turnBugs();

    cout << "\nTapping board..." << endl;
    board.tapBoard();

    cout << "\nAll Bugs After Tap:" << endl;
    board.displayAllBugs();

    return 0;
}
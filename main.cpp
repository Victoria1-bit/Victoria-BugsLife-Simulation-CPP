#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

// Menu display function (NEW)
void displayMenu() {
    cout << "\n========== BUG BOARD MENU ==========" << endl;
    cout << "1. Initialize Bug Board" << endl;
    cout << "2. Display all Bugs" << endl;
    cout << "3. Find a Bug" << endl;
    cout << "4. Tap the Bug Board" << endl;
    cout << "5. Display Life History" << endl;
    cout << "6. Display all Cells" << endl;
    cout << "7. Run Simulation" << endl;
    cout << "8. Exit" << endl;
    cout << "====================================" << endl;
}

int main() {

    srand(time(0));

    cout << "Bug Board Test" << endl;

    Board board;

    // Load bugs from file
    board.loadBugsFromFile("bugs.txt");

    // BEFORE
    cout << "\nAll Bugs Before Tap:" << endl;
    board.displayAllBugs();

    // TURN
    cout << "\nTurning bugs..." << endl;
    board.turnBugs();

    // MOVE
    cout << "\nTapping board..." << endl;
    board.tapBoard();

    // FIGHT
    cout << "\nChecking for fights..." << endl;
    board.fightBugs();

    // AFTER
    cout << "\nAll Bugs After Tap:" << endl;
    board.displayAllBugs();

    // STEP COMPLETE
    cout << "\n--- Simulation Step Complete ---" << endl;

    // NEW: show menu (no logic yet, just display)
    displayMenu();

    return 0;
}
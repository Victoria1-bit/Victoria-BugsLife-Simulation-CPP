#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

// Menu display
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

    // Initial demo run (your existing logic)
    board.loadBugsFromFile("bugs.txt");

    cout << "\nAll Bugs Before Tap:" << endl;
    board.displayAllBugs();

    cout << "\nTurning bugs..." << endl;
    board.turnBugs();

    cout << "\nTapping board..." << endl;
    board.tapBoard();

    cout << "\nChecking for fights..." << endl;
    board.fightBugs();

    cout << "\nAll Bugs After Tap:" << endl;
    board.displayAllBugs();

    cout << "\n--- Simulation Step Complete ---" << endl;

    // NEW: menu loop
    int choice;

    do {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Initialize selected" << endl;
                break;
            case 2:
                cout << "Display bugs selected" << endl;
                break;
            case 3:
                cout << "Find bug selected" << endl;
                break;
            case 4:
                cout << "Tap board selected" << endl;
                break;
            case 5:
                cout << "Life history selected" << endl;
                break;
            case 6:
                cout << "Display cells selected" << endl;
                break;
            case 7:
                cout << "Run simulation selected" << endl;
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 8);

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

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
    cout << "Enter your choice: ";
}

int main() {

    srand(time(0));

    Board board;
    board.loadBugsFromFile("bugs.txt");

    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nInitializing Bug Board..." << endl;
                board.loadBugsFromFile("bugs.txt");
                cout << "Bug Board loaded successfully." << endl;
                break;

            case 2:
                cout << "\n--- All Bugs ---" << endl;
                board.displayAllBugs();
                board.displayBugCount();
                break;

            case 3: {
                int id;
                cout << "Enter Bug ID to search for: ";
                cin >> id;
                board.findBug(id);
                break;
            }

            case 4:
                cout << "\n--- Tapping Bug Board ---" << endl;
                board.turnBugs();
                board.tapBoard();
                board.fightBugs();
                cout << "Tap complete." << endl;
                board.displayAllBugs();
                board.displayBugCount();
                break;

            case 5:
                cout << "\n--- Life History ---" << endl;
                board.displayLifeHistory();
                board.saveLifeHistoryToFile("life_history.txt");
                break;

            case 6:
                cout << "\n--- All Cells ---" << endl;
                board.displayAllCells();
                break;

            case 7:
                board.runSimulation();
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
        }

    } while (choice != 8);

    return 0;
}
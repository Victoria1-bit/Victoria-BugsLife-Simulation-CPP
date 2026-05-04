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
                board.loadBugsFromFile("bugs.txt");
                break;

            case 2:
                board.displayAllBugs();
                break;

            case 3: {
                int id;
                cin >> id;
                board.findBug(id);
                break;
            }

            case 4:
                board.turnBugs();
                board.tapBoard();
                board.fightBugs();
                break;

            case 5:
                board.displayLifeHistory();
                board.saveLifeHistoryToFile("life_history.txt");
                break;

            case 6:
                board.displayAllCells();
                break;

            case 7:
                board.runSimulation();
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
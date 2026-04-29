#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Crawler.h"

using namespace std;

int main() {

    // Seed random number generator (used for direction changes)
    srand(time(0));

    cout << "Crawler Test" << endl;

    // Create a crawler bug
    // ID = 101, starting at (0,0), facing EAST, health = 10
    Crawler crawler1(101, 0, 0, EAST, 10);

    // Display initial state
    cout << "Before move:" << endl;
    crawler1.display();

    // Move the crawler once
    crawler1.move();

    // Display state after moving
    cout << "After move:" << endl;
    crawler1.display();

    return 0;
}
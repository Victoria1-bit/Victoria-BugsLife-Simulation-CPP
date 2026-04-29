#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Crawler.h"
#include "Hopper.h"

using namespace std;

int main() {

    // Seed random number generator
    srand(time(0));

    cout << "Bug Movement Test" << endl;

    // Create a crawler
    // ID 101, position (0,0), facing East, health 10
    Crawler crawler1(101, 0, 0, EAST, 10);

    // Create a hopper
    // ID 102, position (2,2), facing South, health 8, hop length 3
    Hopper hopper1(102, 2, 2, SOUTH, 8, 3);

    cout << "\nBefore move:" << endl;
    crawler1.display();
    hopper1.display();

    // Move both bugs once
    crawler1.move();
    hopper1.move();

    cout << "\nAfter move:" << endl;
    crawler1.display();
    hopper1.display();

    return 0;
}
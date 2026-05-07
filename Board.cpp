#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include "DiagonalBug.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <utility>
#include <ctime>

void Board::loadBugsFromFile(const std::string& filename) {
    for (auto bug : bugs) {
        delete bug;
    }
    bugs.clear();

    std::ifstream file(filename);

    if (!file) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    std::string line;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        std::string value;

        int id, x, y, dir, health, hop;

        getline(ss, type, ';');

        getline(ss, value, ';'); id = stoi(value);
        getline(ss, value, ';'); x = stoi(value);
        getline(ss, value, ';'); y = stoi(value);
        getline(ss, value, ';'); dir = stoi(value);
        getline(ss, value, ';'); health = stoi(value);

        if (type == "C") {
            bugs.push_back(new Crawler(id, x, y, (Direction)dir, health));
        }
        else if (type == "H") {
            getline(ss, value, ';');
            hop = stoi(value);
            bugs.push_back(new Hopper(id, x, y, (Direction)dir, health, hop));
        }
        else if (type == "D") {
            bugs.push_back(new DiagonalBug(id, x, y, (Direction)dir, health));
        }
    }
}

void Board::displayAllBugs() const {
    for (auto bug : bugs) {
        bug->display();
    }
}

void Board::displayBugCount() const {
    int alive = 0;
    int total = bugs.size();

    for (auto bug : bugs) {
        if (bug->isAlive()) {
            alive++;
        }
    }

    std::cout << "\nTotal Bugs: " << total
              << " | Alive: " << alive
              << " | Dead: " << (total - alive) << std::endl;
}

void Board::tapBoard() {
    if (bugs.empty()) {
        return;
    }

    int frozenIndex = rand() % bugs.size();

    std::cout << "Frozen bug this tap: Bug "
              << bugs[frozenIndex]->getId()
              << std::endl;

    for (int i = 0; i < bugs.size(); i++) {
        if (i != frozenIndex && bugs[i]->isAlive()) {
            bugs[i]->move();
        }
    }
}

void Board::turnBugs() {
    for (auto bug : bugs) {
        if (bug->isAlive()) {
            int dir = rand() % 4 + 1;
            bug->setDirection((Direction)dir);
        }
    }
}

void Board::fightBugs() {
    for (int i = 0; i < bugs.size(); i++) {
        for (int j = i + 1; j < bugs.size(); j++) {

            if (bugs[i]->isAlive() && bugs[j]->isAlive()) {
                if (bugs[i]->getPosition() == bugs[j]->getPosition()) {

                    std::cout << "Fight: Bug " << bugs[i]->getId()
                              << " vs Bug " << bugs[j]->getId()
                              << std::endl;

                    for (int round = 1; round <= 3; round++) {
                        if (!bugs[i]->isAlive() || !bugs[j]->isAlive()) {
                            break;
                        }

                        int damageToFirst = rand() % 6;
                        int damageToSecond = rand() % 6;

                        bugs[i]->takeDamage(damageToFirst);
                        bugs[j]->takeDamage(damageToSecond);

                        std::cout << "Round " << round
                                  << ": Bug " << bugs[i]->getId()
                                  << " takes " << damageToFirst
                                  << ", Bug " << bugs[j]->getId()
                                  << " takes " << damageToSecond
                                  << std::endl;
                    }

                    if (!bugs[i]->isAlive()) {
                        std::cout << "Bug " << bugs[i]->getId() << " died." << std::endl;
                    }

                    if (!bugs[j]->isAlive()) {
                        std::cout << "Bug " << bugs[j]->getId() << " died." << std::endl;
                    }
                }
            }
        }
    }
}

void Board::findBug(int id) {
    for (auto bug : bugs) {
        if (bug->getId() == id) {
            bug->display();
            return;
        }
    }

    std::cout << "Bug " << id << " not found." << std::endl;
}

void Board::displayLifeHistory() const {
    for (auto bug : bugs) {
        std::cout << "Bug " << bug->getId() << " path: ";

        for (auto pos : bug->getPath()) {
            std::cout << "(" << pos.first << "," << pos.second << ") ";
        }

        if (bug->isAlive()) {
            std::cout << "Alive";
        }
        else {
            std::cout << "Dead";
        }

        std::cout << std::endl;
    }
}

void Board::displayAllCells() const {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {

            std::cout << "(" << x << "," << y << "): ";

            bool found = false;

            for (auto bug : bugs) {
                if (bug->isAlive() && bug->getPosition() == std::make_pair(x, y)) {
                    std::cout << "Bug " << bug->getId() << " ";
                    found = true;
                }
            }

            if (!found) {
                std::cout << "empty";
            }

            std::cout << std::endl;
        }
    }
}

void Board::displayWinner() const {
    for (auto bug : bugs) {
        if (bug->isAlive()) {
            std::cout << "\nWinner: Bug " << bug->getId() << std::endl;
            return;
        }
    }

    std::cout << "\nNo bugs remaining." << std::endl;
}

void Board::runSimulation() {
    std::cout << "\n--- Running Simulation ---" << std::endl;

    int tapCount = 0;
    const int MAX_TAPS = 20;

    while (true) {
        tapCount++;

        std::cout << "\nTap number: " << tapCount << std::endl;

        turnBugs();
        tapBoard();
        fightBugs();

        displayAllBugs();

        int aliveCount = 0;
        Bug* winner = nullptr;

        for (auto bug : bugs) {
            if (bug->isAlive()) {
                aliveCount++;
                winner = bug;
            }
        }

        std::cout << "\nTotal Bugs: " << bugs.size()
                  << " | Alive: " << aliveCount
                  << " | Dead: " << bugs.size() - aliveCount
                  << std::endl;

        if (aliveCount == 1) {
            std::cout << "\n===== WINNER =====" << std::endl;

            if (winner != nullptr) {
                winner->display();
            }

            break;
        }

        if (tapCount >= MAX_TAPS) {
            std::cout << "\nSimulation stopped after "
                      << MAX_TAPS << " taps." << std::endl;

            if (winner != nullptr) {
                std::cout << "\nCurrent strongest/surviving bug:" << std::endl;
                winner->display();
            }

            break;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    saveLifeHistoryToFile("bugs_life_history");
}

void Board::saveLifeHistoryToFile(const std::string& filename) const {
    std::time_t now = std::time(0);
    std::tm* ltm = std::localtime(&now);

    char buffer[50];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", ltm);

    std::string newFilename = "bugs_life_history_" + std::string(buffer) + ".out";

    std::ofstream outFile(newFilename);

    if (!outFile) {
        std::cout << "Error writing to file" << std::endl;
        return;
    }

    for (auto bug : bugs) {
        outFile << "Bug " << bug->getId() << " path: ";

        for (auto pos : bug->getPath()) {
            outFile << "(" << pos.first << "," << pos.second << ") ";
        }

        if (bug->isAlive()) {
            outFile << "Alive";
        }
        else {
            outFile << "Dead";
        }

        outFile << std::endl;
    }

    std::cout << "Saved to " << newFilename << std::endl;
}

Board::~Board() {
    for (auto bug : bugs) {
        delete bug;
    }
}